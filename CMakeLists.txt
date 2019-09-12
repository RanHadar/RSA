cmake_minimum_required(VERSION 3.12)
project(Ex1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex1 IntegerFactorization.cpp GField.cpp GField.h GFNumber.cpp GFNumber.h)