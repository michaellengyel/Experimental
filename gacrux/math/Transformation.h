//
// Created by michael on 2020. 11. 15..
//

#ifndef EXPERIMENTAL_TRANSFORMATION_H
#define EXPERIMENTAL_TRANSFORMATION_H

#include "../math/Transformation.h"
#include "../io/Scan.h"

class Transformation {
public:

    Transformation(Scan& scan);

    ~Transformation();

    void projection();

    void interpolation();

private:

    Scan& m_scan;

};

#endif //EXPERIMENTAL_TRANSFORMATION_H
