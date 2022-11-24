cmake_minimum_required(VERSION 3.23)
project(hokuyo)

set(CMAKE_CXX_STANDARD 11)

add_executable(GetID main.cpp hokuyo.h hokuyo.cpp)
