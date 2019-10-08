#include <iostream>
using namespace std;

char changeCase(char inChar);

int main(){
	//get user input
	char inChar;
	int operation;
	char result;
	cout << "Enter char, operation" << endl;
	cin >> inChar >> operation;
	//make sure char was entered
	if((int(inChar)<65) || (int(inChar)> 90 && int(inChar) < 97) || (int(inChar > 122))){
		cout << "Result: illegal character" << endl;
		goto breaktag;
	}
	//do operation
	if(operation == 1){
		//change chase function
		result = changeCase(inChar);
		cout << "Result: " << result << endl;
	}else if(operation == 2){
		//change the case
		result = changeCase(inChar);
		int temp = int(result);
		if(temp < 91){
			//find how far letter is from A
			temp -= 65;
			result = char(122 - temp);
		}else{
			temp -= 97;
			result = char(90 - temp);
		}
		cout << "Result: " << result << endl;
	}else if (operation == 3){
		int temp = int(inChar);
		if ((temp > 84) && (temp < 97)){
			temp += 12;
			result = char(temp);
		}else if((temp > 117) && (temp < 122)){
			temp -= 52;
			result = char(temp);
		}else{
			temp += 6;
			result = char(temp);
		}
		cout << "Result: " << result << endl;
	}else{
		cout << "Invalid operation" << endl; 
	}
		
	breaktag:
	return 0;
}
//changes the case of an input charater - upper to lower or lower to upper
char changeCase(char inChar){
	int a = int(inChar);
	if(a < 91){
		return char(a+32);
	}else{
		return char(a-32);
	}
}