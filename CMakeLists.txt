cmake_minimum_required(VERSION 3.17)
project(IGNORE_learn_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(dev/head)

add_executable(IGNORE_learn_cpp dev/devmain.cpp)