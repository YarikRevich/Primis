cmake_minimum_required(VERSION 3.8)
project(Primis VERSION 0.0.1 LANGUAGES CXX)
include(CTest)
set(CMAKE_CXX_FLAGS "-std=c++20")

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/vendor/include/)
add_library(primis STATIC 
src/Primis/Application.cpp
src/Primis/Log.cpp
)

