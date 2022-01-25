/* 
 * protocol_v2.cpp
 * Created on: Jan 25, 2022 22:24
 * Description: 
 * 
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */ 

#include "protocol_v2.hpp"

#include <iostream>

extern "C" {
ProtocolV2 *allocator() { return new ProtocolV2(); }

void deleter(ProtocolV2 *ptr) { delete ptr; }
}

void ProtocolV2::InitializeV2() {
  std::cout << "Calling Initialize from ProtocolV2" << std::endl;
}