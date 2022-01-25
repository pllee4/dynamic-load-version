/*
 * DLLoader.h
 * Created on: Jan 25, 2022 21:16
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef DLLOADER_H
#define DLLOADER_H

#include <dlfcn.h>
#include <memory>
#include <string>

#include <iostream>

namespace dlloader {
template <class T>
class DLLoader {
 public:
  DLLoader(std::string const &pathToLib,
           std::string const &allocClassSymbol = "allocator",
           std::string const &deleteClassSymbol = "deleter")
      : dl_handle_(nullptr),
        lib_path_(pathToLib),
        alloc_symb_(allocClassSymbol),
        delete_symb_(deleteClassSymbol) {}

  ~DLLoader() = default;

  void DLOpenLib() {
    if (!(dl_handle_ = dlopen(lib_path_.c_str(), RTLD_NOW | RTLD_LAZY))) {
      std::cerr << dlerror() << std::endl;
    }
  }

  std::shared_ptr<T> DLGetInstance() {
    using allocClass = T *(*)();
    using deleteClass = void (*)(T *);

    auto alloc_func =
        reinterpret_cast<allocClass>(dlsym(dl_handle_, alloc_symb_.c_str()));
    auto delete_func =
        reinterpret_cast<deleteClass>(dlsym(dl_handle_, delete_symb_.c_str()));

    if (!alloc_func || !delete_func) {
      DLCloseLib();
      std::cerr << dlerror() << std::endl;
    }

    return std::shared_ptr<T>(alloc_func(),
                              [delete_func](T *p) { delete_func(p); });
  }

  void DLCloseLib() {
    if (dlclose(dl_handle_) != 0) {
      std::cerr << dlerror() << std::endl;
    }
  }

 private:
  void *dl_handle_;
  std::string lib_path_;
  std::string alloc_symb_;
  std::string delete_symb_;
};
}  // namespace dlloader

#endif /* DLLOADER_H */
