cmake_minimum_required(VERSION 3.10)

# set the project name
project(Experimental)

# set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# declaring the math library
add_library(math
        gacrux/modules/math/Gaussian_Distribution.cpp
        gacrux/modules/math/Gaussian_Distribution.h
)

# add the executable
add_executable(Experimental gacrux/main.cpp)

# link library to executable
target_link_libraries(Experimental PRIVATE math)
