#ifndef EXPERIMENTAL_POINTS_2D_H
#define EXPERIMENTAL_POINTS_2D_H

#include <cstdint>
#include <vector>

class Points_2D {
public:

    Points_2D() {

    }

    ~Points_2D() {

    }

    class Point_2D {
    public:

        Point_2D(int xCoord, int yCoord, uint8_t luminosity) : m_xCoord(xCoord), m_yCoord(yCoord), m_luminosity(luminosity) {

        }

        ~Point_2D() {

        }

        int m_xCoord;
        int m_yCoord;
        uint8_t m_luminosity;

    };

    std::vector<Point_2D> m_points_2D_vec;

};

#endif //EXPERIMENTAL_POINTS_2D_H
