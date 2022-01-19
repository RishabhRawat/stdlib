cmake_minimum_required(VERSION 3.16)
project(stdlib_implementation)

set(CMAKE_CXX_STANDARD 17)

add_library(stdlib SHARED src/vector.cpp)
add_subdirectory(tests)