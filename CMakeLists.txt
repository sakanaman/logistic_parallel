cmake_minimum_required(VERSION 3.18)

project(logistic)

# pybind11
add_subdirectory(ext/pybind11)

#generate libraly
pybind11_add_module(logistic src/module.cpp)
target_include_directories(logistic PUBLIC include)
