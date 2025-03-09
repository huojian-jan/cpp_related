cmake_minimum_required(VERSION 3.29)
project(atm)

set(CMAKE_CXX_STANDARD 14)

add_executable(atm src/atm.cpp
        include/atm.h
        include/storage.h
        src/storage.cpp)
