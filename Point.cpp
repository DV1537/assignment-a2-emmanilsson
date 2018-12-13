#include <iostream>
#include <cmath>
#include <fstream>


#include "Point.h"


Point::Point(Vector2f* sourcePoints, int numberOfPoints)
{

    this->points = new Vector2f[(numberOfPoints/2)];

    for(int i = 0; i < (numberOfPoints/2); i++)
    {
        this->points[i].x = sourcePoints[i].x;
        this->points[i].y = sourcePoints[i].y;

    }
}


std::string Point::getType()
{
    std::string isPoint;
    isPoint = "Point";
    std::cout << "\nFigure: " << isPoint;

    return isPoint;
}


Point::~Point()
{
    delete[] points;
}