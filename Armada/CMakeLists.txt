cmake_minimum_required(VERSION 3.15)
project(Armada)

set(CMAKE_CXX_STANDARD 17)

add_executable(Armada main.cpp spaceship.cpp spaceship.h fleet.cpp fleet.h)