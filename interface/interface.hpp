/*
 * interface.hpp
 * Created on: Jan 25, 2022 22:08
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <stdexcept>

class Interface {
 public:
  // Interface() = default;
  virtual ~Interface() = default;

  virtual void Initialize() {
    throw std::runtime_error("Please make sure you overide with ProtocolV1");
  }
  virtual void InitializeV2() {
    throw std::runtime_error("Please make sure you overide with ProtocolV2");
  }
};

#endif /* INTERFACE_HPP */
