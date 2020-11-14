#include <iostream>

#include "math/Gaussian_Distribution.h"
#include "logger/Logger.h"

#include "io/Preprocessor.h"
#include "io/Scan.h"

#include <GLFW/glfw3.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/face.hpp"
#include "opencv2/imgproc.hpp"

int main() {

    // Testing Math module...

    std::cout << "Test code running..." << std::endl;

    Gaussian_Distribution first(3.445, 4.234);
    Gaussian_Distribution second(33.445, 42.234);

    Gaussian_Distribution output1 = first + second;

    std::cout << "Output of sigma addition: " << output1.getSigma() << std::endl;
    std::cout << "Output of mu addition: " << output1.getMu() << std::endl;

    Gaussian_Distribution output2 = first * second;

    std::cout << "Output of sigma multiplication: " << output2.getSigma() << std::endl;
    std::cout << "Output of mu multiplication: " << output2.getMu() << std::endl;

    // Testing Logging module...

    Logger logger;
    logger.log("Logger working as expected");

    // Testing OpenCV dependence integration...

    cv::Mat image;
    image = cv::imread("../gacrux/res/images/matrix.jpg");

    if(! image.data ) {
        std::cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    cv::namedWindow("OpenCV Window", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV Window", image);

    std::cout << "Press any key to continue..." << std::endl;
    cv::waitKey(0);

    // Testing lidar data IO...

    // Declaring data container and handling classes
    IOHandler ioHandler("../gacrux/res/scans/4.csv");
    Scan scan;

    // Declaring data processing classes
    Preprocessor preprocessor(scan, ioHandler);

    // Testing GLFW module...

    GLFWwindow *window;

    if(!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(680, 460, "GLFW Window", NULL, NULL);
    if(!window) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Main loop
    while(!glfwWindowShouldClose(window)) {
        //draw();
        //animate();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}