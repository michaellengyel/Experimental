#include <iostream>

#include "math/Gaussian_Distribution.h"
#include "math/Transformation.h"
#include "logger/Logger.h"
#include "visualization/Artist.h"
#include "visualization/Points_2D.h"

#include "io/Preprocessor.h"
#include "io/Scan.h"

#include <GLFW/glfw3.h>

int main() {

    // ########## Testing Math module... ##########

    std::cout << "Test code running..." << std::endl;

    Gaussian_Distribution first(3.445, 4.234);
    Gaussian_Distribution second(33.445, 42.234);

    Gaussian_Distribution output1 = first + second;

    std::cout << "Output of sigma addition: " << output1.getSigma() << std::endl;
    std::cout << "Output of mu addition: " << output1.getMu() << std::endl;

    Gaussian_Distribution output2 = first * second;

    std::cout << "Output of sigma multiplication: " << output2.getSigma() << std::endl;
    std::cout << "Output of mu multiplication: " << output2.getMu() << std::endl;

    // ########## Testing Logging module... ##########

    Logger logger;
    logger.log("Logger working as expected");

    // ########## Testing lidar data IO... ##########

    // Declaring data container and handling classes
    IOHandler ioHandler("../gacrux/res/scans/4.csv");
    Scan scan;

    Points_2D points_2D_360;
    Points_2D points_2D_3D;

    // Declaring data processing classes
    Preprocessor preprocessor(scan, ioHandler);

    // ########## Testing Transformation module... ##########

    Transformation transformation(scan);
    transformation.projection2(points_2D_360, 800, 1900);
    transformation.projection(points_2D_3D, 600, 800);
    transformation.interpolation();

    // ########## Testing Artist OpenCV module... ##########
    Artist artist_points_2D;
    artist_points_2D.renderPoints(points_2D_360, 800, 1900, "360 Degree LIDAR Visualization");

    Artist artist_points_3D;
    artist_points_3D.renderPoints(points_2D_3D, 600, 800, "Projected LIDAR Visualization");

    //  ########## Testing OpenCV dependence integration... ##########
    Artist artist_image;
    artist_image.renderImage("../gacrux/res/images/matrix.jpg", "Reality");

    // ########## Testing GLFW module... ##########

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