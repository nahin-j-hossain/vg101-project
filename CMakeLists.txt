cmake_minimum_required(VERSION 3.16)
project(openGL)

set(CMAKE_CXX_STANDARD 14)

add_executable(openGL main.cpp)

target_link_libraries (openGL -lOpenGL32 -lfreeGLUT)