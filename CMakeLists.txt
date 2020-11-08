cmake_minimum_required(VERSION 3.10)

# set the project name
project(Experimental)

# set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# adding subdirectories
add_subdirectory(gacrux)
#add_subdirectory(gacrux/vendor/glfw)

# declaring the math library

# add the executable
add_executable(${PROJECT_NAME} gacrux/main.cpp)

# add include directories
target_include_directories(${PROJECT_NAME} PUBLIC gacrux/vendor/glfw/include)

# add link to directories
target_link_directories(${PROJECT_NAME} PRIVATE gacrux/vendor/glfw/src)

# link library to executable
target_link_libraries(${PROJECT_NAME} math)
target_link_libraries(${PROJECT_NAME} logger)
target_link_libraries(${PROJECT_NAME} glfw)
