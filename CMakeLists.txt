cmake_minimum_required(VERSION 3.28)
project(towerOfHanoi)

set(CMAKE_CXX_STANDARD 20)
include_directories("/mingw64/include/readline")
include_directories("/mingw64/include/ncurses")
add_executable(towerOfHanoi main.cpp include/TowerOfHanoi.h)

target_link_libraries(towerOfHanoi ncurses /mingw64/lib/libncursesw.a /mingw64/lib/libreadline.a)