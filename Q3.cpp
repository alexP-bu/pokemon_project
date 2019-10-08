#include <iostream>
using namespace std;

int findDistance(int, int);
string convertNumber(int);

int main(){
	 int num1,num2;
	 //get the two numbers
	 cout << "Enter two numbers between 0-100: " << endl;
	 cin >> num1 >> num2; 
	 //output 
	 cout << "Hamming distance between " << num1 << " and " << num2
		  << " when numbers are in ternary format is: " << findDistance(num1,num2) << endl;
	 
	
	return 0;
}

int findDistance(int a, int b){
	//I couldn't figure out the arithmetic way to do it, so I did it by converting to ternary
	//both strings returned are the same length of 5
	string ternary1,ternary2;
	int counter;
	ternary1 = convertNumber(a);
	ternary2 = convertNumber(b);
	for(int i = 0; i < 5; i++){
		if(ternary1[i] != ternary2[i]){
			counter++;
		}
	}
	return counter;
}

string convertNumber(int a){
	//digits in ternary:
	//3^4  3^3 3^2 3^1 3^0
	// 81   27  9   3   1
	//max digits from 0-100 in ternary is 5
	int temp = a;
	string ternaryNum;
	//long division method to convert to ternary
	while(temp > 0){
		int remainder = temp%3;
		ternaryNum = ternaryNum + to_string(remainder);
		temp /= 3;
		if (temp <= 3){
			ternaryNum = ternaryNum + to_string(temp);
			temp = 0;
		}
	}
		return ternaryNum;
}