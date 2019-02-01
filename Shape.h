#include <iostream>

#ifndef SHAPE_H
#define SHAPE_H

#include "Vector.h"


using namespace std;


class Shape{


    private: 
            Vector2f *points;
            
    protected:
        
        int numberOfPoints;
        
    public:
        
        virtual std::string getType();

        virtual double area();

        virtual double circumference();

        virtual double* position();
        
        virtual bool isConvex();


};



#endif // !SHAPE_H