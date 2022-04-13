cmake_minimum_required(VERSION 3.21)
project(hw2)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_executable(hw2 src/main_matrix.cpp
        src/main_matrix_container.cpp
        src/newmain.cpp
        )


