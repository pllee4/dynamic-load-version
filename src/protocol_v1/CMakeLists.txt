add_library(ProtocolV1 SHARED
	protocol_v1.hpp
	protocol_v1.cpp
)

target_link_libraries(ProtocolV1 PUBLIC interface)