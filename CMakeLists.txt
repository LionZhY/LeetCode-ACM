cmake_minimum_required(VERSION 3.15)
project(Dummy)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 仅用来生成编译信息
add_executable(dummy hot100/lc01.cpp)