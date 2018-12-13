#include <iostream>

#include "Shape.h"
#include "Vector.h"

#ifndef POLYGON_H
#define POLYGON_H




class Polygon: public Shape
{

    private: 

        int numberOfPoints; 
        Vector2f *points;
        double centroids[2];

    public:


        Polygon(Vector2f* sourcePoints, int numberOfPoints);
        ~Polygon();

        std::string getType();

        double area(int numberOfPoints, bool isConv); 

        double circumference(int numberOfPoints);

        double* position(int numberOfPoints);

        bool isConvex(int numberOfPoints, bool shapeIsConvex);

        double distance(int numberOfPoints, double *centerPoint);

};




#endif // !POLYGON_H