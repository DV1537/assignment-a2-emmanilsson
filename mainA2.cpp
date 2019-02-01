#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "Shape.h"
#include "Vector.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include "Triangle.h"


using namespace std;


int main(int argc, const char *argv[])
{

    std::ifstream myfile;

    myfile.open(argv[1]);

    
    Vector2f *points; 


    int numberOfCoordinates = 0;

    for (int shapeindex = 0; shapeindex < 1; shapeindex++)
    {


        while (!myfile.eof())
        {
            float a;
            myfile >> a;
            numberOfCoordinates++;

            if (myfile.fail()) 
            {
                std::cout << "Wrong input, program terminates...\n"
                          << "Press [ENTER] to close program";
                getchar();
                getchar();


                exit(EXIT_FAILURE); 
            }
        }

        myfile.close();
        


        
        
        if (numberOfCoordinates % 2 == 0)
        {
            //The amount of coordinates is even
        }
        else
        {
            std::cout << "The amount of coordinates is uneven, program terminates...\n"
                      << "Press [ENTER] to close program";
            getchar();
            getchar();

            exit(EXIT_FAILURE);
        }
        
        
        myfile.open(argv[1]);


        points = new Vector2f[(numberOfCoordinates / 2)];

        for(int i = 0; i < (numberOfCoordinates/2); i++)
        {
            myfile >> points[i].x; 
            myfile >> points[i].y;
        }
    }
   
    myfile.close();


    /*std::cout << "Input: ";
    for (int i = 0; i < numberOfCoordinates/2; i++)
    {
        std::cout << fixed << std::setprecision(3) << points[i].x << ", " << points[i].y << ", ";
     
    }

    std::cout << "\n";*/




    




    Shape shape;

    
    if(numberOfCoordinates == 2)
    {
        Point point(points, numberOfCoordinates);

        point.getType();

        point.area();

        point.circumference();
        
        point.position();
        
        point.isConvex();

    }


    else if(numberOfCoordinates == 4)
    {
        Line line(points, numberOfCoordinates);

        line.getType();

        line.area();

        line.circumference();

        line.isConvex();

        line.position();
        

    }


    else if (numberOfCoordinates == 6)
    {
        
        Triangle triangle(points, numberOfCoordinates);
        
        triangle.getType();

        triangle.area();

        double a, b, c;
        triangle.circumference(a, b, c);

        
        triangle.isConvex(); 

        double centerX, centerY;
        triangle.position(numberOfCoordinates);

        triangle.distance(numberOfCoordinates, centerX, centerY);
    
    }


    else if (numberOfCoordinates > 6)
    {

        Polygon polygon(points, numberOfCoordinates);
        
        polygon.getType();

        bool conv;
        std::cout << "\nConvex: " << polygon.isConvex(numberOfCoordinates, conv);

        polygon.area(numberOfCoordinates, conv);


        double perimeter;
        perimeter = polygon.circumference(numberOfCoordinates);
        
        std::cout << "\nCircumference: " << perimeter;

        
        polygon.position(numberOfCoordinates);

        
    }


    delete[] points;
    points = nullptr;
    
      
    return 0;
}