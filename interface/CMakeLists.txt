add_library(interface INTERFACE)
target_include_directories(interface INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
