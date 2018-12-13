#include <iostream>
#include <cmath>
#include <fstream>

#include "Triangle.h"

//funktionskropparna, class:: etcetcetc
//Ta bort triangelminnet sist efter det i main! :D
//Här ska det intressanta hända!

Triangle::Triangle(Vector2f* sourcePoints, int numberOfPoints)
{
    
    this->points = new Vector2f[(numberOfPoints/2)];

    for(int i = 0; i < (numberOfPoints/2); i++)
    {
        this->points[i].x = sourcePoints[i].x;
        this->points[i].y = sourcePoints[i].y;

    }


}


std::string Triangle::getType()
{
    std::string isTriangle;
    isTriangle = "Triangle";
    std::cout << "Figure: " << isTriangle << "\n";
    return isTriangle;
}

double Triangle::area()
{
    
        int n = 0;
        double areaOfTriangle;
        areaOfTriangle = ((points[n].x * (points[1].y - points[2].y)) + (points[1].x * (points[2].y - points[n].y)) + (points[2].x * (points[n].y - points[1].y)))/2;

        areaOfTriangle = abs(areaOfTriangle);
        
        //Print the area with a decimal precision of 3
        areaOfTriangle = round(areaOfTriangle * 1000) / 1000;

        std::cout << "\nArea: " << areaOfTriangle;
   
    return areaOfTriangle;
}



double Triangle::circumference(double distanceA, double distanceB, double distanceC)
{

    //Denna funktionen räknar ut omkretsen på en triangel

    distanceA = pow(points[0].x - points[1].x, 2) + pow(points[0].y - points[1].y, 2);
    distanceB = pow(points[1].x - points[2].x, 2) + pow(points[1].y - points[2].y, 2);
    distanceC = pow(points[2].x - points[0].x, 2) + pow(points[2].y - points[0].y, 2);

    distanceA = sqrt(distanceA);
    distanceB = sqrt(distanceB);
    distanceC = sqrt(distanceC);

    this->perimeter  = distanceA + distanceB + distanceC;

    perimeter = round(perimeter * 1000) / 1000;

    std::cout << "\nCircumference: " << this->perimeter;
    
    return this->perimeter;
  
}

double* Triangle::position(double centroidX, double centroidY)
{

    centroidX = (points[0].x + points[1].x + points[2].x)/3;
    centroidY = (points[0].y + points[1].y + points[2].y)/3;

    std::cout << "\n" << "Centroid: " << "(" << centroidX << ", " << centroidY << ")";

    centroidX = round(centroidX * 1000) / 1000;
    centroidY = round(centroidY * 1000) / 1000;

    double* center;

    delete center;
    
    center = NULL;
    return center;
    
}


bool Triangle::isConvex()
{

    bool shapeIsConvex;
    shapeIsConvex = true; //All triangles with 3 points is convex

    if (shapeIsConvex == true)
        std::cout << " \n" << "Convex: " << shapeIsConvex << "\n";

    return true;
    

}

Triangle::~Triangle()
{
    delete[] points;
    points = NULL;
}