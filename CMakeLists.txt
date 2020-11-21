cmake_minimum_required(VERSION 3.10)

# set the project name
project(Experimental)

# set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(OpenCV_DIR /home/michael/libraries/build)

# adding subdirectories
add_subdirectory(gacrux)
add_subdirectory(gacrux/vendor/glfw)

# declaring the math library

# add the executable
add_executable(${PROJECT_NAME} gacrux/main.cpp gacrux/visualization/Artist.cpp gacrux/visualization/Artist.h gacrux/visualization/Artist.h)

# add include directories
target_include_directories(${PROJECT_NAME} PUBLIC gacrux/vendor/glfw/include)

# add link to directories
target_link_directories(${PROJECT_NAME} PRIVATE gacrux/vendor/glfw/src)

# link library to executable
target_link_libraries(${PROJECT_NAME} io)
target_link_libraries(${PROJECT_NAME} math)
target_link_libraries(${PROJECT_NAME} logger)
target_link_libraries(${PROJECT_NAME} glfw)

# Linking OpenCV to project (NEEDED)
find_package( OpenCV REQUIRED )
set(OpenCV_DIR "/usr/local/include/opencv")
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

#set(OpenCV_DIR /home/michael/libraries/opencv-master/include/opencv2)
#include_directories(${OpenCV_INCLUDE_DIR})
#link_directories(${OpenCV_LINK_DIR})
#target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

#set(OpenCV_DIR /home/michael/libraries/build)

#set(OpenCV_INCLUDE_DIRS
#        /home/michael/libraries/opencv-master/include
#        /home/michael/libraries/opencv-contrib-master/include
#        /home/michael/libraries/build/include
#        )
#
#set(OpenCV_LIB_DIR
#        /home/michael/libraries/build/lib
#        )
#
#set(OpenCV_LIBS
#        opencv_core
#        opencv_highgui
#        opencv_imgcodecs
#        )
#
#include_directories(${OpenCV_INCLUDE_DIRS})
#link_directories(${OpenCV_LIB_DIR})
#target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
