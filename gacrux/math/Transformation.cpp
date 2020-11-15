#include "Transformation.h"

Transformation::Transformation(Scan& scan) : m_scan(scan) {

}

Transformation::~Transformation() {

}

void Transformation::projection() {

    int offset = 300;
    int magnificaton = 10;

    int x = 0;
    int y = 0;

    for (int i = 0; i < m_scan.m_data.size(); i++) {
        m_scan.m_data.at(i).m_point.m_xPos  = (m_scan.m_data.at(i).m_point.m_xPos * magnificaton + offset);
        m_scan.m_data.at(i).m_point.m_yPos  = (m_scan.m_data.at(i).m_point.m_yPos * magnificaton + offset);
    }
}

void Transformation::interpolation() {

}