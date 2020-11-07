cmake_minimum_required(VERSION 3.10)

# set the project name
project(Experimental)

# set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# adding subdirectories
add_subdirectory(gacrux)

# declaring the math library

# add the executable
add_executable(Experimental gacrux/main.cpp)

# link library to executable
target_link_libraries(Experimental PRIVATE math)
target_link_libraries(Experimental PRIVATE logger)

# based on guide:
# https://www.youtube.com/watch?v=SYgESCQeGJY
