cmake_minimum_required(VERSION 3.10.0)

project(CppLab VERSION 0.1.0 LANGUAGES C CXX)

# 设置可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(my_app main.cpp BoxRuntime.cpp BoxRuntime.hpp Box.cpp Box.hpp)