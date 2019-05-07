cmake_minimum_required(VERSION 3.14)
project(Price_Is_Right)

set(CMAKE_CXX_STANDARD 14)

add_executable(Price_Is_Right main.cpp Digit.cpp Digit.h Adafruit_NeoPixel.cpp Adafruit_NeoPixel.h Number.cpp Number.h)