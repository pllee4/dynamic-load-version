#include <iostream>
#include <memory>
#include <string>

#include "DLLoader.h"
#include "interface.hpp"
#include "path.h"

using namespace std;

#ifdef WIN32
std::string protocol_V1_path = std::string(LIB_PATH) + "libProtocolV1.dll";
std::string protocol_V2_path = std::string(LIB_PATH) + "libProtocolV2.dll";
#endif
#ifdef __linux__
std::string protocol_V1_path = std::string(LIB_PATH) + "libProtocolV1.so";
std::string protocol_V2_path = std::string(LIB_PATH) + "libProtocolV2.so";
#endif
#ifdef __APPLE__
std::string protocol_V1_path = std::string(LIB_PATH) + "libProtocolV1.dylib";
std::string protocol_V2_path = std::string(LIB_PATH) + "libProtocolV2.dylib";
#endif

void Initialize(const std::string& path) {
  dlloader::DLLoader<Interface> dlloader(path);
  dlloader.DLOpenLib();

  // scoped is required to ensure destry of shared_ptr before dll is closed
  {
    std::shared_ptr<Interface> inst = dlloader.DLGetInstance();

    if (path == protocol_V1_path)
      inst->Initialize();
    else if (path == protocol_V2_path)
      inst->InitializeV2();
  }
  dlloader.DLCloseLib();
}

int main(int argc, char** argv) {
  if (argc == 2) {
    std::string protocol{argv[1]};
    if (protocol == "V1") {
      Initialize(protocol_V1_path);
    } else if (protocol == "V2") {
      Initialize(protocol_V2_path);
    } else {
      std::cout << "Protocol " << protocol << " not supported!" << std::endl;
      return -1;
    }
  } else {
    std::cout << "Usage: app <protocol>" << std::endl
              << "Supported protocol: V1, V2" << std::endl
              << "Example ./app V1" << std::endl;
    return -1;
  }
  return 0;
}