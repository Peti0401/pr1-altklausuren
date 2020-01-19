cmake_minimum_required(VERSION 3.15)
project(Flughafen)

set(CMAKE_CXX_STANDARD 17)

add_executable(Flughafen main.cpp passenger.cpp passenger.h flight.cpp flight.h)