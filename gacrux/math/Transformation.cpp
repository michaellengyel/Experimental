#include "Transformation.h"

Transformation::Transformation(Scan& scan) : m_scan(scan) {

}

Transformation::~Transformation() {

}

void Transformation::projection(Points_2D& points_2D, double height, double width) {

    //Translations
    double translationXYZ = 0;

    double offsetX = 0;
    double offsetY = 0;
    double offsetZ = 0;

    double A00 = translationXYZ;
    double A01 = offsetX;
    double A02 = offsetY;

    double A10 = offsetX;
    double A11 = translationXYZ;
    double A12 = offsetZ;

    double A20 = offsetY;
    double A21 = offsetZ;
    double A22 = translationXYZ;

    // Rotations Z
    double thetaZ = 0;

    double B00 = (cos(thetaZ * 3.141592653589793 / 180.0));
    double B01 = (sin(thetaZ * 3.141592653589793 / 180.0));
    double B02 = 0;

    double B10 = (-sin(thetaZ * 3.141592653589793 / 180.0));
    double B11 = (cos(thetaZ * 3.141592653589793 / 180.0));
    double B12 = 0;

    double B20 = 0;
    double B21 = 0;
    double B22 = 1;

    // Rotations Y
    double thetaY = 0;

    double C00 = (cos(thetaY * 3.141592653589793 / 180.0));
    double C01 = 0;
    double C02 = (sin(thetaY * 3.141592653589793 / 180.0));

    double C10 = 0;
    double C11 = 1;
    double C12 = 0;

    double C20 = (-sin(thetaY * 3.141592653589793 / 180.0));
    double C21 = 0;
    double C22 = (cos(thetaY * 3.141592653589793 / 180.0));

    // Rotations X
    double thetaX = 30;

    double D00 = 1;
    double D01 = 0;
    double D02 = 0;

    double D10 = 0;
    double D11 = (cos(thetaX * 3.141592653589793 / 180.0));
    double D12 = (-sin(thetaX * 3.141592653589793 / 180.0));

    double D20 = 0;
    double D21 = (sin(thetaX * 3.141592653589793 / 180.0));
    double D22 = (cos(thetaX * 3.141592653589793 / 180.0));

    for (int i = 0; i < m_scan.m_data.size(); i++) {

        double x = m_scan.m_data.at(i).m_point.m_xPos;
        double y = m_scan.m_data.at(i).m_point.m_yPos;
        double z = m_scan.m_data.at(i).m_point.m_zPos;

        // Translations
        x  += ((x * A00) + (y * A01) + (z * A02));
        y  += ((x * A10) + (y * A11) + (z * A12));
        z  += ((x * A20) + (y * A21) + (z * A22));

        // Rotations Z
        x  += ((x * B00) + (y * B01) + (z * B02));
        y  += ((x * B10) + (y * B11) + (z * B12));
        z  += ((x * B20) + (y * B21) + (z * B22));

        // Rotations Y
        x  += ((x * C00) + (y * C01) + (z * C02));
        y  += ((x * C10) + (y * C11) + (z * C12));
        z  += ((x * C20) + (y * C21) + (z * C22));

        // Rotations X
        x  += ((x * D00) + (y * D01) + (z * D02));
        y  += ((x * D10) + (y * D11) + (z * D12));
        z  += ((x * D20) + (y * D21) + (z * D22));

        // Fix offset of image:
        x += width/2;
        y += height/2;

        points_2D.m_points_2D_vec.push_back(Points_2D::Point_2D(static_cast<int>(x), static_cast<int>(y), static_cast<uint8_t>(0)));

    }

}

void Transformation::projection2(Points_2D& points_2D, double height, double width) {

    double scalingFactor = (static_cast<double>(width)/360.0);
    double radToDeg = 180.0/3.141592653589793;

    for (int i = 0; i < m_scan.m_data.size(); i++) {

        double x = m_scan.m_data.at(i).m_point.m_xPos;
        double y = m_scan.m_data.at(i).m_point.m_yPos;
        double z = m_scan.m_data.at(i).m_point.m_zPos;

        double dist = (sqrt((pow(x, 2) + pow(y, 2))));

        double angleInRad = 0;
        double angleInDeg = 0;
        double angleWithOffset = 0;
        double angleWithScaling = 0;

        if (x > 0 && y > 0) {
            angleInRad = cosh(y/dist);
            angleInDeg = angleInRad * radToDeg;
            angleWithOffset = angleInDeg + 180;
            angleWithScaling = angleWithOffset * scalingFactor;
        } else if (x < 0 && y > 0) {
            angleInRad = cosh(y/dist);
            angleInDeg = angleInRad * radToDeg;
            angleWithOffset = 180 - angleInDeg;
            angleWithScaling = angleWithOffset * scalingFactor;
        } else if (x < 0 && y < 0) {
            angleInRad = cosh(y/dist);
            angleInDeg = angleInRad * radToDeg;
            angleWithOffset = 90 - angleInDeg;
            angleWithScaling = angleWithOffset * scalingFactor;
        } else if (x > 0 && y < 0) {
            angleInRad = cosh(y/dist);
            angleInDeg = angleInRad * radToDeg;
            angleWithOffset = angleInDeg + 270;
            angleWithScaling = angleWithOffset * scalingFactor;
        } else {
            angleWithScaling = 0;
        }

        // Calculate the scaled y (based on x and y)
        double scaledY = 0;
        scaledY = height - (z * 60 + height / 2);

        // Calculate the scaled z (based on x, y, z)
        double scaledZ = (sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)))) * 255/50;

        points_2D.m_points_2D_vec.push_back(Points_2D::Point_2D(static_cast<int>(angleWithScaling), static_cast<int>(scaledY), static_cast<uint8_t>(scaledZ)));

    }

}

void Transformation::interpolation() {

}