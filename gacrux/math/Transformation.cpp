#include "Transformation.h"

Transformation::Transformation(Scan& scan) : m_scan(scan) {

}

Transformation::~Transformation() {

}

void Transformation::projection() {

    //Translations
    double translationXYZ = 10;

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
    double thetaX = 0;

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

        // Translations
        m_scan.m_data.at(i).m_point.m_xPos  = ((m_scan.m_data.at(i).m_point.m_xPos * A00) + (m_scan.m_data.at(i).m_point.m_yPos * A01) + (m_scan.m_data.at(i).m_point.m_zPos * A02));
        m_scan.m_data.at(i).m_point.m_yPos  = ((m_scan.m_data.at(i).m_point.m_xPos * A10) + (m_scan.m_data.at(i).m_point.m_yPos * A11) + (m_scan.m_data.at(i).m_point.m_zPos * A12));
        m_scan.m_data.at(i).m_point.m_zPos  = ((m_scan.m_data.at(i).m_point.m_xPos * A20) + (m_scan.m_data.at(i).m_point.m_yPos * A21) + (m_scan.m_data.at(i).m_point.m_zPos * A22));

        // Rotations Z
        m_scan.m_data.at(i).m_point.m_xPos  = ((m_scan.m_data.at(i).m_point.m_xPos * B00) + (m_scan.m_data.at(i).m_point.m_yPos * B01) + (m_scan.m_data.at(i).m_point.m_zPos * B02));
        m_scan.m_data.at(i).m_point.m_yPos  = ((m_scan.m_data.at(i).m_point.m_xPos * B10) + (m_scan.m_data.at(i).m_point.m_yPos * B11) + (m_scan.m_data.at(i).m_point.m_zPos * B12));
        m_scan.m_data.at(i).m_point.m_zPos  = ((m_scan.m_data.at(i).m_point.m_xPos * B20) + (m_scan.m_data.at(i).m_point.m_yPos * B21) + (m_scan.m_data.at(i).m_point.m_zPos * B22));

        // Rotations Y
        m_scan.m_data.at(i).m_point.m_xPos  = ((m_scan.m_data.at(i).m_point.m_xPos * C00) + (m_scan.m_data.at(i).m_point.m_yPos * C01) + (m_scan.m_data.at(i).m_point.m_zPos * C02));
        m_scan.m_data.at(i).m_point.m_yPos  = ((m_scan.m_data.at(i).m_point.m_xPos * C10) + (m_scan.m_data.at(i).m_point.m_yPos * C11) + (m_scan.m_data.at(i).m_point.m_zPos * C12));
        m_scan.m_data.at(i).m_point.m_zPos  = ((m_scan.m_data.at(i).m_point.m_xPos * C20) + (m_scan.m_data.at(i).m_point.m_yPos * C21) + (m_scan.m_data.at(i).m_point.m_zPos * C22));

        // Rotations X
        m_scan.m_data.at(i).m_point.m_xPos  = ((m_scan.m_data.at(i).m_point.m_xPos * D00) + (m_scan.m_data.at(i).m_point.m_yPos * D01) + (m_scan.m_data.at(i).m_point.m_zPos * D02));
        m_scan.m_data.at(i).m_point.m_yPos  = ((m_scan.m_data.at(i).m_point.m_xPos * D10) + (m_scan.m_data.at(i).m_point.m_yPos * D11) + (m_scan.m_data.at(i).m_point.m_zPos * D12));
        m_scan.m_data.at(i).m_point.m_zPos  = ((m_scan.m_data.at(i).m_point.m_xPos * D20) + (m_scan.m_data.at(i).m_point.m_yPos * D21) + (m_scan.m_data.at(i).m_point.m_zPos * D22));
    }

    /*
    int offset = 300;
    int magnificaton = 10;

    int x = 0;
    int y = 0;

    for (int i = 0; i < m_scan.m_data.size(); i++) {
        m_scan.m_data.at(i).m_point.m_xPos  = (m_scan.m_data.at(i).m_point.m_xPos * magnificaton + offset);
        m_scan.m_data.at(i).m_point.m_yPos  = (m_scan.m_data.at(i).m_point.m_yPos * magnificaton + offset);
    }
    */
}

void Transformation::interpolation() {

}