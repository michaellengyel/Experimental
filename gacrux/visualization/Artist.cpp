//
// Created by michael on 2020. 11. 18..
//

#include "Artist.h"

Artist::Artist() {

}

Artist::~Artist() {

}

void Artist::drawLine( cv::Mat img, cv::Point start, cv::Point end, int luminosity) {

    int thickness = 1;
    int lineType = cv::LINE_8;
    int correctedLuminosity = (-luminosity+255);
    int r, g;

    line(img, start, end, cv::Scalar( 0, correctedLuminosity, luminosity ),thickness, lineType );
}