cmake_minimum_required(VERSION 3.10.2)

project(dynamic_load_version VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

## Put all binary files into /bin and libraries into /lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/bin)

add_subdirectory(lib)
add_subdirectory(interface)
add_subdirectory(src)