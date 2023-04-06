cmake_minimum_required(VERSION 3.24)
project(DataStructureSample)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructureSample main.cpp Person.cpp Person.hpp Courses.cpp Courses.hpp Schedule.cpp Schedule.hpp)
