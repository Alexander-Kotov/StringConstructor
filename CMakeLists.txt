cmake_minimum_required(VERSION 3.2)

project(StringConstructor C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH}) 

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
