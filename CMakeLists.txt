cmake_minimum_required(VERSION 3.18)

project(rogistic)

# pybind11
add_subdirectory(ext/pybind11)

#generate libraly
pybind11_add_module(rogistic src/module.cpp)
target_include_directories(rogistic PUBLIC include)
