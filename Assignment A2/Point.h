#include <iostream>

#ifndef POINT_H
#define POINT_H

#include "Shape.h"
#include "Vector.h"

class Point: public Shape
{

    private:

        int numberOfPoints;
        Vector2f *points;

    public:

        Point(Vector2f* sourcePoints, int numberOfPoints);
        ~Point();

        std::string getType();


};



#endif // !POINT_H