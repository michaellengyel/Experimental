//
// Created by michael on 2020. 11. 15..
//

#ifndef EXPERIMENTAL_TRANSFORMATION_H
#define EXPERIMENTAL_TRANSFORMATION_H

#include <math.h>
#include <vector>

#include "../math/Transformation.h"
#include "../io/Scan.h"
#include "../visualization/Points_2D.h"

class Transformation {
public:

    Transformation(Scan& scan);

    ~Transformation();

    void projection(Points_2D& points_2D, double height, double width);

    void projection2(Points_2D& points_2D, double height, double width);

    void interpolation();

private:

    Scan& m_scan;

};

#endif //EXPERIMENTAL_TRANSFORMATION_H
