#include "Vector2D.h"

#include <iostream>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;
//default constructor
Vector2D::Vector2D(){
	x = 0;
	y = 0;
}
//constructor with input x and y
Vector2D::Vector2D(double x_in, double y_in){
	x = x_in;
	y = y_in;
}

//non member function operators
ostream& operator<< (ostream &out, Vector2D v1){
	out << "<" << v1.x << ", " << v1.y << ">";
	return out;
}

Vector2D operator*(Vector2D v1, double d){
	Vector2D newV;
	
	newV.x = v1.x *d;
	newV.y = v1.y *d;
	
	return newV;
}

Vector2D operator/(Vector2D v1, double d){
	Vector2D newV;
	
	if (d == 0){
		newV.x = v1.x;
		newV.y = v1.y;
		
		return newV;
	}else{
		
	newV.x = v1.x / d;
	newV.y = v1.y / d;
	
	return newV;
	}
	
}		