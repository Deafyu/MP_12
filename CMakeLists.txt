cmake_minimum_required(VERSION 3.15)
project(MP_12)

set(CMAKE_CXX_STANDARD 17)

add_executable(MP_12 main.cpp libs/CSortTable.cpp libs/CSortTable.h libs/libExceptions.cpp libs/libExceptions.h libs/CTable.cpp libs/CTable.h)