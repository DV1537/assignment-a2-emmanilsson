#include <iostream>

#include "Shape.h"
#include "Vector.h"


#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle: public Shape
{

    private: 

        double perimeter = 0;
        int numberOfPoints; 
        Vector2f *points; 
            
    public:

        Triangle(Vector2f *sourcePointss, int amountOfPoints);
        
        ~Triangle();

        string getType();

        double area();

        double circumference(double distanceA, double distanceB, double distanceC);

        double* position(int numberOfPoints);

        double distance(int numberOfPoints, double centerPointX, double centerPointY);

        bool isConvex();

};

#endif // !TRIANGLE_H