cmake_minimum_required(VERSION 3.23)
project(matrix_calculator_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(matrix_calculator_cpp main.cpp matrix/Matrix.cpp matrix/Matrix.h test/test-matrix.cpp test/test-matrix.h)
