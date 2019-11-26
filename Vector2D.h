#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

using namespace std;

class Vector2D{
	public:
//public members x and y coordinates
	double x;
	double y;
	//base constructors
	Vector2D();
	Vector2D(double, double);
};
//overloaded functions
Vector2D operator*(Vector2D, double);
Vector2D operator/(Vector2D, double);
ostream& operator<<(ostream &out, Vector2D);
#endif