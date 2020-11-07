#include <iostream>

#include "math/Gaussian_Distribution.h"
#include "logger/Logger.h"

int main() {

    std::cout << "Test code running..." << std::endl;

    Gaussian_Distribution first(3.445, 4.234);
    Gaussian_Distribution second(33.445, 42.234);

    Gaussian_Distribution output1 = first + second;

    std::cout << "Output of sigma addition: " << output1.getSigma() << std::endl;
    std::cout << "Output of mu addition: " << output1.getMu() << std::endl;

    Gaussian_Distribution output2 = first * second;

    std::cout << "Output of sigma multiplication: " << output2.getSigma() << std::endl;
    std::cout << "Output of mu multiplication: " << output2.getMu() << std::endl;

    // Testing Logging module
    Logger logger;
    logger.log("Logger working as expected");

    return 0;
}