cmake_minimum_required(VERSION 3.15)
project(Airport)

set(CMAKE_CXX_STANDARD 17)

add_executable(Airport main.cpp flight.h flight.cpp passenger.h passenger.cpp category.h)