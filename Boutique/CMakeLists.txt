cmake_minimum_required(VERSION 3.15)
project(Boutique)

set(CMAKE_CXX_STANDARD 17)

add_executable(Boutique main.cpp garment.cpp garment.h boutique.cpp boutique.h)