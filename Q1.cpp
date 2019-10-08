#include<iostream>
using namespace std;

int main(){
	//intialize an array for input
	float GPA = 0.0;
	string grades[5];
	float gradeNums[5];
	string checks[10] = {"A","A-","B+","B","B-","C+","C","C-","D","F"};
	//get all grades and check their inputs using a loop
	for(int i = 0; i<=4; i++){
		cout << "Class: " << i+1 << endl;
		cin >> grades[i];
		//check for valid input using for loop and a boolean
		bool isEqual = false; 
		for(int j = 0; j <=9; j++){
			if(grades[i] == checks[j]){
					isEqual = true;
			}
		}
		//if grades doesn't equal a valid grade go to end of main 
		if(isEqual == false){
			cout << "Invalid input!" << endl;
			goto breaktag;
		}
	}
	//if the program has made it here, proper grades are in
	//convert them to numbers
	for(int i = 0; i<=4; i++){
		if(grades[i] == "A"){
			gradeNums[i] = 4;
		}
		else if(grades[i] == "A-"){
			gradeNums[i] = 3.7;
		}
		else if(grades[i] == "B+"){
			gradeNums[i] = 3.3;
		}
		else if(grades[i] == "B"){
			gradeNums[i] = 3.0;
		}
		else if(grades[i] == "B-"){
			gradeNums[i] = 2.7;
		}
		else if(grades[i] == "C+"){
			gradeNums[i] = 2.3;
		}
		else if(grades[i] == "C"){
			gradeNums[i] = 2.0;
		}
		else if(grades[i] == "C-"){
			gradeNums[i] = 1.7;
		}
		else if(grades[i] == "D"){
			gradeNums[i] = 1.0;
		}
		else{
			gradeNums[i] = 0;
		}
	}
	
	
	//avg all grades and output GPA
	for (int i = 0; i<=4; i++){
		GPA += gradeNums[i];
	}
	cout << "GPA: " << GPA/5.0 << endl;
	
	breaktag:
	return 0;
}