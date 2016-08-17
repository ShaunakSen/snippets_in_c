cmake_minimum_required(VERSION 3.5)
project(snippets_c__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(snippets_c__ ${SOURCE_FILES})