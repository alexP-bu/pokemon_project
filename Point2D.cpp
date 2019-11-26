#include "Point2D.h"
#include "Vector2D.h"

#include <string>
#include "math.h"


using namespace std;
//default constructor
Point2D::Point2D(){
	x = 0;
	y = 0;
}
//constructor with input x and y
Point2D::Point2D(double x_in, double y_in){
	x = x_in;
	y = y_in;
}

//non member function
double GetDistanceBetween(Point2D p1, Point2D p2){
	double x1 = p1.x;
	double x2 = p2.x;
	double y1 = p1.y;
	double y2 = p1.y;
	
	double xSq = pow(fabs(x1-x2),2);
	double ySq = pow(fabs(x1-x2),2);
	
	return sqrt(xSq + ySq);
}

//non member function operators
ostream& operator<< (ostream &out, Point2D p1){
	out << "(" << p1.x << ", " << p1.y << ")";
	return out;
}

Point2D operator+(Point2D p1, Point2D p2){
	Point2D newP;
	
	newP.x = p1.x + p2.x;
	newP.y = p1.y + p2.y;
	
	return newP;
}

Vector2D operator-(Point2D p1, Point2D p2){
	Vector2D newV;
	
	newV.x = p1.x - p2.x;
	newV.y = p1.y - p2.y;
	
	return newV;
}

bool operator==(Point2D p1, Point2D p2){
	if((p1.x == p2.x) && (p1.y == p2.y)){
		return true;
	}else{
		return false;
	}
}	