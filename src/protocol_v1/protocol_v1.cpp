/*
 * protocol_v1.cpp
 * Created on: Jan 25, 2022 22:19
 * Description:
 *
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */

#include "protocol_v1.hpp"

#include <iostream>

extern "C" {
ProtocolV1 *allocator() { return new ProtocolV1(); }

void deleter(ProtocolV1 *ptr) { delete ptr; }
}

void ProtocolV1::Initialize() {
  std::cout << "Calling Initialize from ProtocolV1" << std::endl;
}