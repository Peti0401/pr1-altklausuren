cmake_minimum_required(VERSION 3.15)
project(PizzaBude)

set(CMAKE_CXX_STANDARD 17)

add_executable(PizzaBude main.cpp topping.cpp topping.h pizza.cpp pizza.h)