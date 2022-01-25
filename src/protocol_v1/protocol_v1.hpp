/* 
 * protocol_v1.hpp
 * Created on: Jan 25, 2022 22:16
 * Description: 
 * 
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */ 

#ifndef PROTOCOL_V1_HPP
#define PROTOCOL_V1_HPP

#include "interface.hpp"

class ProtocolV1 : public Interface
{
public:
	ProtocolV1() = default;
	~ProtocolV1() = default;

	void Initialize() override;
};

#endif /* PROTOCOL_V1_HPP */
