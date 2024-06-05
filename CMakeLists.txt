cmake_minimum_required(VERSION 3.28)
project(towerOfHanoi)

set(CMAKE_CXX_STANDARD 20)

add_executable(towerOfHanoi main.cpp
        include/TowerOfHanoi.h
)
