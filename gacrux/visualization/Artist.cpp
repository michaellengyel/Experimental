//
// Created by michael on 2020. 11. 18..
//

#include "Artist.h"

Artist::Artist() {

}

Artist::~Artist() {

}

void Artist::renderPoints(Scan& scan, int width, int height, std::string title) {

    cv::Mat image(width, height, CV_8UC3, cv::Scalar(0, 0, 0));

    for (int i = 0; i < scan.m_data.size(); i++) {
        //artist.drawLine(grHistogram, cv::Point(scan.m_data.at(i).m_point.m_xPos + imageSizeY/2, scan.m_data.at(i).m_point.m_yPos + imageSizeX/2), cv::Point(scan.m_data.at(i).m_point.m_xPos + imageSizeY/2, scan.m_data.at(i).m_point.m_yPos + imageSizeX/2), scan.m_data.at(i).m_point.m_zPos);
        drawLine(image, cv::Point(scan.m_data.at(i).m_point.m_xPos, scan.m_data.at(i).m_point.m_yPos), cv::Point(scan.m_data.at(i).m_point.m_xPos, scan.m_data.at(i).m_point.m_yPos), scan.m_data.at(i).m_point.m_zPos);
    }

    if(! image.data ) {
        throw std::runtime_error("Could not open file!");
    }

    cv::namedWindow("OpenCV Drawing", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV Drawing", image);

    std::cout << "Press any key to continue..." << std::endl;
    cv::waitKey(0);

}

void Artist::renderImage(std::string name, std::string title) {

    cv::Mat image;
    image = cv::imread(name);

    if(! image.data ) {
        throw std::runtime_error("Could not open file!");
    }

    cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
    cv::imshow(title, image);

    std::cout << "Press any key to continue..." << std::endl;
    cv::waitKey(0);
}

void Artist::drawLine(cv::Mat images, cv::Point start, cv::Point end, int luminosity) {

    int thickness = 1;
    int lineType = cv::LINE_8;
    int invertedLuminosity = (-luminosity+255);

    line(images, start, end, cv::Scalar( 0, invertedLuminosity, luminosity ),thickness, lineType);
}