cmake_minimum_required(VERSION 3.10)

# set the project name
project(Experimental)

# set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# add the executable
add_executable(Experimental modules/main.cpp modules/Gaussian_Distribution.cpp modules/Gaussian_Distribution.h)
