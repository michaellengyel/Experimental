//
// Created by michael on 2020. 11. 18..
//

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/face.hpp>
#include <opencv2/imgproc.hpp>

#ifndef EXPERIMENTAL_ARTIST_H
#define EXPERIMENTAL_ARTIST_H

class Artist {
public:

    Artist();

    ~Artist();

    void drawLine( cv::Mat img, cv::Point start, cv::Point end, int luminosity);

};

#endif //EXPERIMENTAL_ARTIST_H
