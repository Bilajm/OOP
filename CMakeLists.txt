cmake_minimum_required(VERSION 3.20)
project(OOP)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP main.cpp Container.h Text.h Replace.h Shift.h Container.cpp Replace.cpp Text.cpp Shift.cpp)
