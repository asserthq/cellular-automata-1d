cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(cellular-automata)

add_executable(ca src/main.cpp src/cellauto.h src/cycle.h)
