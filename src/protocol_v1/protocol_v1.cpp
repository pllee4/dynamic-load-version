/*
 * protocol_v1.cpp
 * Created on: Jan 25, 2022 22:19
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "protocol_v1.hpp"

#include <iostream>

#if defined(__linux__) || defined(__APPLE__)
extern "C" {
ProtocolV1 *allocator() { return new ProtocolV1(); }

void deleter(ProtocolV1 *ptr) { delete ptr; }
}
#endif

#ifdef WIN32
extern "C" {
__declspec(dllexport) ProtocolV1 *allocator() { return new ProtocolV1(); }

__declspec(dllexport) void deleter(ProtocolV1 *ptr) { delete ptr; }
}
#endif

void ProtocolV1::Initialize() {
  std::cout << "Calling Initialize from ProtocolV1" << std::endl;
}