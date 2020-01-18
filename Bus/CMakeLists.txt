cmake_minimum_required(VERSION 3.15)
project(Bus)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bus main.cpp bus.cpp bus.h fleet.cpp fleet.h)