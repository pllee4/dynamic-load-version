include(app.cmake)
add_executable(app ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(app PRIVATE ${CMAKE_BINARY_DIR}/src/app/include)
target_link_libraries(app PUBLIC interface dlloader ${CMAKE_DL_LIBS})