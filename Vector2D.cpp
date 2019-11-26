#include "Vector2D.h"

#include <iostream>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;
//default constructor
Vector2D::Vector2D(){
	//set x and y to zero
	x = 0;
	y = 0;
}
//constructor with input x and y
Vector2D::Vector2D(double x_in, double y_in){
	//x is equal to inputtd x
	x = x_in;
	//y is equal to inputted y
	y = y_in;
}

//non member function operators
// << operator for ostream
ostream& operator<< (ostream &out, Vector2D v1){
	//should look like: <num,num>
	out << "<" << v1.x << ", " << v1.y << ">";
	return out;
}

//operator for multiplication
Vector2D operator*(Vector2D v1, double d){
	//make a new vector
	Vector2D newV;
	//multiply!
	newV.x = v1.x *d;
	newV.y = v1.y *d;
	//return vector
	return newV;
}
//same as multiplication, but now with division
Vector2D operator/(Vector2D v1, double d){
	
	Vector2D newV;
	
	if (d == 0){
		//if 0 is inputted just return previous vector
		newV.x = v1.x;
		newV.y = v1.y;
		
		return newV;
	}else{
		//else divide 
	newV.x = v1.x / d;
	newV.y = v1.y / d;
	
	return newV;
	}
	
}		