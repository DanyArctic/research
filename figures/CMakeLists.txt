cmake_minimum_required(VERSION 3.15)
project(figures)

set(CMAKE_CXX_STANDARD 20)

add_executable(figures main.cpp Figure.h Rectangle.cpp Rectangle.h Circle.cpp Circle.h Quadrate.cpp Quadrate.h)