add_library(dlloader INTERFACE)
if (WIN32)
	set(DLLOADER_INC ${CMAKE_CURRENT_SOURCE_DIR}/Windows)
endif(WIN32)

if (UNIX)
	set(DLLOADER_INC ${CMAKE_CURRENT_SOURCE_DIR}/Unix)
endif(UNIX)

target_include_directories(dlloader INTERFACE
	$<BUILD_INTERFACE:${DLLOADER_INC}>)