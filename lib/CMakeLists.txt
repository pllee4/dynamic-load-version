add_library(dlloader INTERFACE)
target_include_directories(dlloader INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/DLLoader>)