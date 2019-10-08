#include<iostream>
using namespace std;

int main(){
	int input,reverse,temp,copyInput;
	cout << "Enter a number: " << endl;
	cin >> input,copyInput;
	//check if input was a valid integer
	if(input == 0){
		cout << "Invalid Input" << endl;
		goto breaktag;
	}
	//save a copy of the input
	copyInput = input;
	//find reversed integer
	while(input != 0){
		//mod finds a the rightmost digit and stores it in temp
		temp = input % 10;
		//move previous digit over by one and add temp
		reverse = reverse * 10 + temp;
		//get rid of last digit
		input /= 10;
	}
	//test if the numbers are equal
	if(reverse == copyInput){
		cout << "The number " << copyInput << " is a palindrome" << endl;
	}else{
		cout << "The number " << copyInput << " isn't a palindrome" << endl;
	}
	
	breaktag:
	return 0;
}