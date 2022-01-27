/*
 * protocol_v2.cpp
 * Created on: Jan 25, 2022 22:24
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "protocol_v2.hpp"

#include <iostream>

#if defined(__linux__) || defined(__APPLE__)
extern "C" {
ProtocolV2 *allocator() { return new ProtocolV2(); }

void deleter(ProtocolV2 *ptr) { delete ptr; }
}
#endif

#ifdef WIN32
extern "C" {
__declspec(dllexport) ProtocolV2 *allocator() { return new ProtocolV2(); }

__declspec(dllexport) void deleter(ProtocolV2 *ptr) { delete ptr; }
}
#endif

void ProtocolV2::InitializeV2() {
  std::cout << "Calling Initialize from ProtocolV2" << std::endl;
}