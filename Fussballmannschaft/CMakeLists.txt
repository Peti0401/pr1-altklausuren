cmake_minimum_required(VERSION 3.15)
project(Fussballmannschaft)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fussballmannschaft main.cpp spieler.cpp spieler.h mannschaft.cpp mannschaft.h)