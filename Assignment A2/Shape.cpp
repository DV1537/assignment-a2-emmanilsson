#include <iostream>
#include <fstream>
#include <string>

#include "Shape.h"



using namespace std;


std::string Shape::getType()
{
    //Types are defined in respective class

    std::string type;

    return type;
}

double Shape::area()
{   
    int defaultArea = -1;
    std::cout << "\nArea: " << defaultArea;

    return defaultArea;
}


double Shape::circumference()
{
    int defaultPerimeter = -1;
    std::cout << "\nCircumference: " << defaultPerimeter;

    return defaultPerimeter; 
}


double *Shape::position()
{
    double *centroid;
    std::cout << "\nCentroid: -";

    delete centroid;

    return centroid;
    
}



bool Shape::isConvex()
{
    bool shapeIsConvex;
    shapeIsConvex = true;

    if (shapeIsConvex == shapeIsConvex)
    {
        shapeIsConvex = true;
        std::cout << "\n" << "Convex: - " << "\n";
    }

    return true;
}
