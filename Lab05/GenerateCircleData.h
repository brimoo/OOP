#ifndef GenerateCircleData_h
#define GenerateCircleData_h

#include "Vec.h"
#include <cmath>

void generateCircleData(std::vector<Vec*>& points, const Vec& center, float radius, int resolution){
    
    // Clear the points vector to make sure it's empty before you start
    points.clear();

    for(int i = 0; i < resolution; i++){

        float angle = (2 * M_PI / resolution) * i;
        float x = radius * cos(angle) + center.getX();
        float y = radius * sin(angle) + center.getY();

        Vec * point = new Vec(x, y);
        points.push_back(point);

    }
    
}

#endif
