add_library(ProtocolV2 SHARED
	protocol_v2.hpp
	protocol_v2.cpp
)

target_link_libraries(ProtocolV2 PUBLIC interface)
