//
// Created by michael on 2020. 11. 18..
//

#include <string>
#include <iostream>

#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/face.hpp>
//#include <opencv2/imgproc.hpp>

#include "Points_2D.h"

#ifndef EXPERIMENTAL_ARTIST_H
#define EXPERIMENTAL_ARTIST_H

class Artist {
public:

    Artist();

    ~Artist();

    void renderImage(std::string name, std::string title);

    void renderPoints(Points_2D& points_2D, int width, int height, std::string name);

private:

    void drawLine(cv::Mat image, cv::Point start, cv::Point end, int luminosity);

};

#endif //EXPERIMENTAL_ARTIST_H
