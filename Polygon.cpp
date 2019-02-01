#include <iostream>
#include <cmath>
#include <fstream>

#include "polygon.h"

Polygon::Polygon(Vector2f *sourcePoints, int numberOfPoints)
{

    this->points = new Vector2f[(numberOfPoints / 2)];

    for (int i = 0; i < (numberOfPoints / 2); i++)
    {
        this->points[i].x = sourcePoints[i].x;
        this->points[i].y = sourcePoints[i].y;
    }
}

std::string Polygon::getType()
{
    std::string isPolygon;
    isPolygon = "Polygon";
    std::cout << "\nFigure: " << isPolygon;
    return isPolygon;
}



bool Polygon::isConvex(int numberOfPoints, bool shapeIsConvex)
{

    shapeIsConvex = false;

    double dx1, dy1, dx2, dy2, crproduct;

    //All polygons with 4 points are convex, it would take atleast 5 points to make it intersect for example
    if ((numberOfPoints / 2) == 4)
        return true;

    //In a polygon, all interior angles has to be less than 180 degrees in order for it to be convex.
    for (int i = 0; i < (numberOfPoints / 2); i++)
    {
        dx1 = points[(i + 2) % (numberOfPoints / 2)].x - points[(i + 1) % (numberOfPoints / 2)].x;
        dy1 = points[(i + 2) % (numberOfPoints / 2)].y - points[(i + 1) % (numberOfPoints / 2)].y;

        dx2 = points[i].x - points[(i + 1) % (numberOfPoints / 2)].x;
        dy2 = points[i].y - points[(i + 1) % (numberOfPoints / 2)].y;

        crproduct = (dx1 * dy2) - (dy1 * dx2);
        
        if (i == 0)
        {
            shapeIsConvex = crproduct > 0;
        }
        else if (shapeIsConvex != (crproduct > 0))
        {
            return false;
        }
    }

    return true;
    
    area(numberOfPoints, shapeIsConvex);

    //Had to add a third return in order to make the area function call work 
    bool convex = true;
    return true;

}

// https://stackoverflow.com/questions/471962/how-do-i-efficiently-determine-if-a-polygon-is-convex-non-convex-or-complex

//IsConvex funkar! :D
double Polygon::area(int numberOfPoints, bool isConv)
{

    double areaOfPolygon = 0.0;

        if(isConvex(numberOfPoints, isConv))
        {
        // Im using the shoelace formula for the polygon area
        int j = (numberOfPoints / 2) - 1;

        for (int i = 0; i < (numberOfPoints / 2); i++)
        {
            areaOfPolygon += (points[j].x + points[i].x) * (points[j].y - points[i].y);
            j = i; // j is previous vertex to i
        }

        areaOfPolygon = fabs(areaOfPolygon / 2);

        areaOfPolygon = areaOfPolygon * pow(10, 3);
        areaOfPolygon = floor(areaOfPolygon);
        areaOfPolygon = areaOfPolygon / pow(10, 3);

        std::cout << "\nArea: " << areaOfPolygon;

        return areaOfPolygon;
    
        }

    else
    {
        areaOfPolygon = -1;
        std::cout << "\nArea: " << areaOfPolygon;

        return areaOfPolygon;
    }

}

//https://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/


double Polygon::circumference(int numberOfPoints)
{

    double centroid = 0, dx, dy;

    for (int i = 0; i < (numberOfPoints / 2); i++)
    {
        dx = points[(i + 1) % (numberOfPoints / 2)].x - points[i].x;
        dy = points[(i + 1) % (numberOfPoints / 2)].y - points[i].y;
        centroid += sqrt(dx * dx + dy * dy);
    }

    centroid = centroid * pow(10, 3);
    centroid = floor(centroid);
    centroid = centroid / pow(10, 3);

    return centroid;
}

double* Polygon::position(int numberOfPoints)
{

    double *centroid = new double[2];
    centroid[0] = 0;
    centroid[1] = 0;


        for (int i = 0; i < (numberOfPoints / 2); i++)
        {
            centroid[0] = centroid[0] + points[i].x;
            centroid[1] = centroid[1] + points[i].y;
        }

        centroid[0] = centroid[0] / (numberOfPoints / 2);
        centroid[1] = centroid[1] / (numberOfPoints / 2);

        centroid[0] = centroid[0] * pow(10, 3);
        centroid[0] = floor(centroid[0]);
        centroid[0] = centroid[0] / pow(10, 3);

        centroid[1] = centroid[1] * pow(10, 3);
        centroid[1] = floor(centroid[1]);
        centroid[1] = centroid[1] / pow(10, 3);


        std::cout << "\nCentroid: "
                  << "(" << centroid[0] << ", " << centroid[1] << ")";

    
    
    distance(numberOfPoints, centroid);
    
    delete centroid;

    centroid = NULL;


    return centroid;


}

double Polygon::distance(int numberOfPoints, double *centerPoint)
{

    double x1, x2, y1, y2;
    double distanceX, distanceY, distance;

    x1 = centerPoint[0];
    y1 = centerPoint[1];

    //Since there is only one shape, I chose to compare the centroid to another point far away from the centroid
    x2 = (numberOfPoints / 2) + 10;
    y2 = (numberOfPoints / 2) + 10;

    //I'm using the distance formula, previously used for calculating circumference for triangle and polygon
    distanceX = pow(x1 - x2, 2);
    distanceY = pow(y1 - y2, 2);

    distance = distanceX + distanceY;
    distance = sqrt(distance);

    distance = distance * pow(10, 3);
    distance = floor(distance);
    distance = distance / pow(10, 3);

    //'centroid = round(centroid * 1000) / 1000;

    std::cout << "\nDistance: " << distance;

    delete centerPoint;
    centerPoint = NULL;

    return distance;
}



Polygon::~Polygon()
{
    delete[] points;
    points = NULL;
}