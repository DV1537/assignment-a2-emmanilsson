#include <iostream>



#include "Line.h"


Line::Line(Vector2f* sourcePoints, int numberOfPoints)
{

    this->points = new Vector2f[(numberOfPoints/2)];

    for(int i = 0; i < (numberOfPoints/2); i++)
    {
        this->points[i].x = sourcePoints[i].x;
        this->points[i].y = sourcePoints[i].y;

    }
}


std::string Line::getType()
{
    std::string isLine;
    isLine = "Line";
    std::cout << "\nFigure: " << isLine;

    return isLine;
}


Line::~Line()
{
    delete[] points;
    points = NULL;
}