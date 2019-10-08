#include <iostream>
#include <math.h>
using namespace std;

int main(){
	//define all variables
	int xcord1,ycord1,xcord2,ycord2,area1,area2,slength1,slength2,
	
		bottomcornerx1,bottomcornerx2,bottomcornery2,bottomcornery1;
	//Get information of squares from user
	cout << "Enter information for the first square" << endl;
	cout << "x-coordinate: " << endl;
	cin >> xcord1;
	cout << "y-coordinate: " << endl;
	cin >> ycord1;
	cout << "Enter area: " << endl;
	cin >> area1;
	cout << "Enter information for the second square" << endl;
	cout << "x-coordinate: " << endl;
	cin >> xcord2;
	cout << "y-coordinate: " << endl;
	cin >> ycord2;
	cout << "Enter area: " << endl;
	cin >> area2;
	//find the length of one side, then find bottom corners
	slength1 = sqrt(area1);
	slength2 = sqrt(area2);
	bottomcornerx1 = xcord1 + slength1;
	bottomcornery1 = ycord1 + slength1;
	bottomcornerx2 = xcord2 + slength2;
	bottomcornery2 = ycord2 + slength2;
	//compare positions of the two squares using the sides
	//to see if they intersect
	//they wont intersect if they are either side by side OR on top of one another
	if((xcord1 > bottomcornerx2 || xcord2 > bottomcornerx1)){
		cout << "THE SQAURES DO NOT INTERSECT" << endl;
	}else if((ycord1 < bottomcornery2) || (ycord2 < bottomcornery1)){
		cout << "THE SQUARES INTERSECT" << endl;
	}
	return 0;
}