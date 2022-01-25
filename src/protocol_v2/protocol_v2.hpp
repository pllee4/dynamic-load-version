/* 
 * protocol_v2.hpp
 * Created on: Jan 25, 2022 22:25
 * Description: 
 * 
 * Copyright (c) 2022 Pin Loon Lee (pllee4)
 */ 

#ifndef PROTOCOL_V2_HPP
#define PROTOCOL_V2_HPP

#include "interface.hpp"

class ProtocolV2 : public Interface
{
public:
	ProtocolV2() = default;
	~ProtocolV2() = default;

	void InitializeV2() override;
};

#endif /* PROTOCOL_V2_HPP */
