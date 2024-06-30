cmake_minimum_required(VERSION 3.18)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Calculator main.cpp HighPrecisionFloat.cpp HighPrecisionFloat.h Calculator.cpp Calculator.h)
