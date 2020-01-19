cmake_minimum_required(VERSION 3.15)
project(HandyApps)

set(CMAKE_CXX_STANDARD 17)

add_executable(HandyApps main.cpp app.cpp app.h cellular.cpp cellular.h)