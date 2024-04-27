cmake_minimum_required(VERSION 3.15)

project(SimpleCompiler)

set(CMAKE_CXX_STANDARD 20)

file(COPY input DESTINATION ${CMAKE_BINARY_DIR})

add_executable(compiler src/main.cpp)