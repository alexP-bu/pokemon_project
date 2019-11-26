#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

#include "Vector2D.h"

using namespace std;

class Point2D{
	public:
//public members x and y coordinates
	double x;
	double y;
	Point2D();
	Point2D(double, double);
	
};
//non member function
double GetDistanceBetween(Point2D, Point2D);
//overloaded functions
Point2D operator+(Point2D, Point2D);
//overloaded the == function for later
bool operator==(Point2D, Point2D);
Vector2D operator-(Point2D, Point2D);
ostream& operator<<(ostream &out, Point2D);

#endif