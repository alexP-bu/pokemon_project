#include "pa2Functions.h"
#define PI 3.14159
extern int ENTRIES;
extern string* inputPtr;
extern int entryCount;
extern bool writing;
using namespace std;

//write data to file function
void writeDataToFile(const char * fileName){
	cout << "Writing output of program to file " << fileName << "\n";
	ofstream file2;
	file2.open(fileName);
	
	if(file2.is_open){
		writing = true;
	}else{
		cout << "File open error - make sure a file with your name is made!";
	}
}
//initialize function
void initialize(){
	cout << "  _________________________________ " << "\n";
	cout << " /	 By-Alexander-Pozin       /| " << "\n";
	cout << "/________________________________/ |" << "\n";
	cout << "|--Software-Engineering--EC327--|  |" << "\n";
	cout << "|------Fall-Semester--2019------|  |" << "\n";
	cout << "|---Programming-Assignment--2---|  |" << "\n";
	cout << "|_______________________________|  |" << "\n";
	cout << "|----Value-of-Entries-is--" << ENTRIES << "----|  |" << "\n";
	cout << "|-------------------------------| /" << "\n";
	cout << "|_______________________________|/" << "\n";
	cout << "\n";
}
//check code to see if its valid
bool checkCode(string inputCode){
	if (   inputCode == "F"
	    || inputCode == "f"
		|| inputCode == "B"
		|| inputCode == "b"
		|| inputCode == "R"
		|| inputCode == "r"
		|| inputCode == "U"
		|| inputCode == "u"
		|| inputCode == "C"
		|| inputCode == "c"
		|| inputCode == "E"
		|| inputCode == "e"
		|| inputCode == "K"
		|| inputCode == "k"
		|| inputCode == "S"
		|| inputCode == "s"
		|| inputCode == "N"
		|| inputCode == "n"
		|| inputCode == "X"
		|| inputCode == "x"
		|| inputCode == "L"
		|| inputCode == "l"
		|| inputCode == "Y"
		|| inputCode == "y"
		|| inputCode == "D"
		|| inputCode == "d"
		|| inputCode == "I"
		|| inputCode == "i"
		|| inputCode == "O"
		|| inputCode == "o"
		|| inputCode == "Q"
		|| inputCode == "q"){
			return true;
		}else{
			return false;
		}
}
//factorial function
int factorial(int inputNum){
	if (inputNum > 1){
		return inputNum * factorial(inputNum - 1);
	}else{
		return 1;
	}
}
//fibonacci function
int fibonacci(int inputNum){
	int output = 1;
	if (inputNum > 2){
		output = fibonacci(inputNum - 1) + fibonacci(inputNum - 2);
	}else{
		return output;
	}
}
//find square root function
double findSqrtValue(double a){
	return sqrt(a);
}
//find area of square given side
double areaSquare(double a){
	return a*a;
}
//find area of circle given radius
double areaCircle(double a){
	return PI*a*a;
}
//natural log function
double naturalLog(double a){
	return log(a);
}
//find next odd value
int findNextOddValue(int a){
	
	if (a % 2 == 0){
		return a + 1;
	}else{
		return a + 2;
	}
}
//find next even value
int findNextEvenValue(int a){
	if(a % 2 == 0){
		return a + 2;
	}else{
		return a + 1;
	}
}
//generate random value using system time and the agrument as a seed
double lucky(double a){
	srand(time(NULL));
	double b = rand() % 100;
	srand(a);
	double c = rand() % 100;
	return (c * b);
}
//get user input with delta value
bool getUserInput(double* a, double* b, double* c){
	//get user input
	cout << "Please input first value:" << "\n";
	cin >> *a;
	cout << "Please enter last value" << "\n";
	cin >> *b;
	cout << "Please enter delta: " << "\n";
	cin >> *c;
	//check if computation is needed
	if ((*c <= 0) || (*a > *b)){
		cout << "No computation needed" << "\n";
		return false;
	}else{
		return true;
	}
}
//do math function for sin/cos
double doMath(double a, char b){
	if(b == 's'){
		return sin(a);
	}else if(b == 'c'){
		return cos(a);
	}else if(b == 'x'){
		return exp(a);
	}
}
//find nyancatvalue function
double findNyanCatValue(double a){
	
	return (pow (4 * a, a)) + a + 10;
}
//read commands from a file specified by user input
void readDataFromFile(const char * fileName){
	ifstream file1;
	file1.open(fileName);
	string line;
	int counter = 1;
	//get file input
	if(file1.is_open()){
		while(!(file1.eof())){
			getline(file1,line);
			//run commands based on input  -if counter is even, it is a command line, if odd, it's input line
			//format string by removing any newlines - needed to do this for windows
			//because all files must end in q it'll work
			cout << "Line " << counter << " in file reads: " << line << "\n";
			line.erase(line.size() - 1);
			//now run the commands
			if((counter % 2) == 1){
				//if quit
				if((line == "q") || (line == "Q")){
					break;
				//if its a single input
			    }else if((line == "f") || (line == "F") || (line == "b") || (line == "B")){
					//move to next line of file, save current line
					string temp;
					counter++;
					temp = line;
					getline(file1,line);
					cout << "Line " << counter << " in file reads: " << line << "\n";
					//remove the newline character at the end
					line.erase(line.size() - 1);
					//convert to integer
					stringstream inputConversion(line);
					double input = 0;
					inputConversion >> input;
					//run command with integer as input
					runCommand(temp, input);
				//if its two inputs	
				}else if((line == "d") || (line == "D") || (line == "e") || (line == "E")){
					//move to next line of file, save current line
					counter++;
					string temp;
					temp = line;
					getline(file1,line);
					cout << "Line " << counter << " in file reads: " << line << "\n";
					//remove the newline character at the end
					//split string at space
					char* half2;
					char* tempread;
					char* buf = strdup(line.c_str());
					tempread = strtok(buf, " ");
					half2 = strtok(NULL, " ");
					//convert to integer
					stringstream inputConversion(line);
					double input1 = 0;
					inputConversion >> input1;
					stringstream inputConversion2(half2);
					double input2 = 0;
					inputConversion2 >> input2;
					//run command with integer as input
					runCommand(temp,input1,input2);
				//if three inputs	
				}else{
					//move to next line of file, save current line
					counter++;
					string temp;
					temp = line;
					getline(file1,line);
					cout << "Line " << counter << " in file reads: " << line << "\n";
					//remove the newline character at the end
					//split string at space
					char* half2;
					char* half3;
					char* tempread;
					char* buf = strdup(line.c_str());
					tempread = strtok(buf, " ");
					half2 = strtok(NULL, " ");
					half3 = strtok(NULL, " ");
					//convert to integer
					stringstream inputConversion(line);
					double input1 = 0;
					inputConversion >> input1;
					//second part
					stringstream inputConversion2(half2);
					double input2 = 0;
					inputConversion2 >> input2;
					//third part
					double input3 = 0;
					stringstream inputConversion3(half3);
					inputConversion3 >> input3;
					//run command with integer as input
					runCommand(temp,input1,input2, input3);
				}
			}
			counter++;
		}
		file1.close();
		cout << "reading quit - finished" << "\n";
	}else{
		cout << "File open error" << "\n";
	}
}
//get user input without delta value
bool getUserInput(double * a,double * b){
	//get user input
	cout << "Please input first value:" << "\n";
	cin >> *a;
	cout << "Please enter last value" << "\n";
	cin >> *b;
	
	if(*a > *b){
		cout << "No computation needed" << "\n";
		return false;
	}else{
		return true;
	}
}
//get command name to print output text
string getCommandName(string inputCommand){
	
	
	string out;
	if((inputCommand == "r" || inputCommand == "R")){
		return "square root";
	}else if((inputCommand == "u" || inputCommand == "U")){
		return  "square area"; 
	}else if((inputCommand == "c" || inputCommand == "C")){
		return "circle area";
	}else if((inputCommand == "e" || inputCommand == "E")){
		return "even";
	}else if((inputCommand == "k" || inputCommand == "K")){
		return "lucky number";
	}else if((inputCommand == "s" || inputCommand == "S")){
		return "sin";
	}else if((inputCommand == "n" || inputCommand == "N")){
		return "cos";
	}else if((inputCommand == "x" || inputCommand == "X")){
		return "exponentials";
	}else if((inputCommand == "l" || inputCommand == "L")){
		return "log";
	}else if((inputCommand == "y" || inputCommand == "Y")){
		return "nyan cat value";
	}else if((inputCommand == "d" || inputCommand == "D")){
		return "odd";
	}else if((inputCommand == "i" || inputCommand == "I")){
		return "read input commands from file";
	}else if((inputCommand == "o" || inputCommand == "O")){
		return "output to file";
	}else if((inputCommand == "f" || inputCommand == "F")){
		return "factorial";
	}else if((inputCommand == "b" || inputCommand == "B")){
		return "fibonacci";
	}else if((inputCommand == "q" || inputCommand == "Q")){
		return "quit";
	}
}
//get user input with only 1 input
void getUserInput(double * a){
	
	cout << "Please input value:" << "\n";
	cin >> *a;
}
//master function for running a command that isn't a write read or quit
void runCommand(string inputCommand){	
	double first = 0, last = 0, delta = 0;
	double* f = &first; 
	double* l = &last; 
	double* d = &delta;
	if((inputCommand == "f" || inputCommand == "F")){
			//Compute the Factorial value Given an integer number;
			getUserInput(f);
			cout << "Factorial of " << first << " is " << factorial(first) << "\n";
	}else if((inputCommand == "b" || inputCommand == "B")){
			//Compute the fiBonacci number Given an integer index
			getUserInput(f);
			cout << "Fibonacci number at index " << first << " is " << fibonacci(first) << "\n";
	}else if((inputCommand == "r" || inputCommand == "R")){
			//Compute square Roots The sqrt <cmath> function
			if (getUserInput(f,l,d) == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Square root of " << last << " is " << findSqrtValue(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Square root of " << first + i << " is " << findSqrtValue(first + i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "u" || inputCommand == "U")){
			//Compute the area of SqUare values Given the length of a side
			if (getUserInput(f,l,d) == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Area of square with side length " << last << " is " << areaSquare(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Area of square with side length " << first + i << " is " << areaSquare(first + i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "c" || inputCommand == "C")){
			//Compute the area of Circle values Given the radius of a circle
			if (getUserInput(f,l,d) == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Area of circle with radius length " << last << " is " << areaCircle(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Area of square with radius length " << first + i << " is " << areaCircle(first + i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "e" || inputCommand == "E")){
			//Compute Even numbers List even numbers between “first” and “last” number provided (ignore delta)
			if (getUserInput(f,l) == true){
				cout << "Even numbers in between " << (int)first << " and " << (int)last << ": \n";
				for(int i = (int)first; i < (int)last - 2; i+=2){
					cout << findNextEvenValue(i) << "\n";
				}
			}
	}else if((inputCommand == "k" || inputCommand == "K")){
			//Compute LucKy numbers Use random number function
			if(getUserInput(f,l,d) == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Lucky number: " << lucky(first+i) << "\n";
						entryCount++;
						break;
					}
					cout << "Lucky number: " << lucky(first+i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "s" || inputCommand == "S")){
			//Compute Sin values The sin <cmath> function
			if (getUserInput(f,l,d) == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Sin of " << last << " is " << doMath(last, 's') << "\n";
						entryCount++;
						break;
					}
					cout << "Sin of " << first + i << " is " << doMath(first + i, 's') << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "n" || inputCommand == "N")){
			//The sin <cmath> function The cos <cmath> function
			if (getUserInput(f,l,d) == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Cos of " << last << " is " << doMath(last, 'c') << "\n";
						entryCount++;
						break;
					}
					cout << "Cos of " << first + i << " is " << doMath(first + i, 'c') << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "x" || inputCommand == "X")){
			//Compute EXponentials The exp <cmath> function
			if (getUserInput(f,l,d) == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "exponential of " << last << " is " << doMath(last, 'x') << "\n";
						entryCount++;
						break;
					}
					cout << "exponential of " << first + i << " is " << doMath(first + i, 'x') << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "l" || inputCommand == "L")){
			//Compute Natural Logs The log <cmath> function
			if (getUserInput(f,l,d) == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Natural log of " << last << " is " << naturalLog(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Natural log of " << first + i << " is " << naturalLog(first + i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "y" || inputCommand == "Y")){
			//Compute NYanCat value
			if (getUserInput(f,l,d) == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Nyancat value of " << last << " is " << findNyanCatValue(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Nyancat value of " << first + i << " is " << findNyanCatValue(first + i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "d" || inputCommand == "D")){
			//Compute oDd numbers List odd numbers between “first” and “last” number provided (ignore delta)
			if (getUserInput(f,l) == true){
				cout << "Odd numbers in between " << (int)first << " and " << (int)last << ": \n";
				for(int i = (int)first; i < (int)last - 2; i+=2){
					cout << findNextOddValue(i) << "\n";
				}
			}
	}else{
		cout << "invalid command entered, moving on...." << "\n";
	}		
}
//function for write command with one input
void runCommand(string inputCommand, double in){
	double first = in;
	if((inputCommand == "f") || (inputCommand == "F")){
			//Compute the Factorial value Given an integer number;
			cout << "Factorial of " << first << " is " << factorial(first) << "\n";
	}else if((inputCommand == "b" || inputCommand == "B")){
			//Compute the fiBonacci number Given an integer index
			cout << "Fibonacci number at index " << first << " is " << fibonacci(first) << "\n";
	}else{
		cout << "invalid command entered, moving on...." << "\n";
	}
}
//function for write command with two inputs
void runCommand(string inputCommand, double in1, double in2){
	double first = in1;
	double last = in2;
	//check if computation is needed
	bool computationNeeded = false;
	if(first > last){
		cout << "No computation needed" << "\n";
		computationNeeded = false;
	}else{
		computationNeeded = true;
	}
	
	if((inputCommand == "e" || inputCommand == "E")){
			//Compute Even numbers List even numbers between “first” and “last” number provided (ignore delta)
			if (computationNeeded == true){
				cout << "Even numbers in between " << (int)first << " and " << (int)last << ": \n";
				for(int i = (int)first; i < (int)last - 2; i+=2){
					cout << findNextEvenValue(i) << "\n";
				}
			}
	}else if((inputCommand == "d" || inputCommand == "D")){
			//Compute oDd numbers List odd numbers between “first” and “last” number provided (ignore delta)
			if (computationNeeded == true){
				cout << "Odd numbers in between " << (int)first << " and " << (int)last << ": \n";
				for(int i = (int)first; i < (int)last - 2; i+=2){
					cout << findNextOddValue(i) << "\n";
				}
			}
	}else{
		cout << "invalid command entered, moving on...." << "\n";
	}
}
//function for write command with 3 inputs
void runCommand(string inputCommand, double in1, double in2, double in3){
	double first = in1, last = in2, delta = in3;
	double* f = &first; 
	double* l = &last; 
	double* d = &delta;
	bool computationNeeded = false;
	//check if computation is needed
	if ((delta <= 0) || (first > last)){
		cout << "No computation needed" << "\n";
		computationNeeded = false;
	}else{
		computationNeeded = true;
	}
	
	if((inputCommand == "r" || inputCommand == "R")){
			//Compute square Roots The sqrt <cmath> function
			if (computationNeeded == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Square root of " << last << " is " << findSqrtValue(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Square root of " << first + i << " is " << findSqrtValue(first + i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "u" || inputCommand == "U")){
			//Compute the area of SqUare values Given the length of a side
			if (computationNeeded == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Area of square with side length " << last << " is " << areaSquare(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Area of square with side length " << first + i << " is " << areaSquare(first + i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "c" || inputCommand == "C")){
			//Compute the area of Circle values Given the radius of a circle
			if (computationNeeded == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Area of circle with radius length " << last << " is " << areaCircle(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Area of square with radius length " << first + i << " is " << areaCircle(first + i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "k" || inputCommand == "K")){
			//Compute LucKy numbers Use random number function
			if(computationNeeded == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Lucky number: " << lucky(first+i) << "\n";
						entryCount++;
						break;
					}
					cout << "Lucky number: " << lucky(first+i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "s" || inputCommand == "S")){
			//Compute Sin values The sin <cmath> function
			if (computationNeeded == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Sin of " << last << " is " << doMath(last, 's') << "\n";
						entryCount++;
						break;
					}
					cout << "Sin of " << first + i << " is " << doMath(first + i, 's') << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "n" || inputCommand == "N")){
			//The sin <cmath> function The cos <cmath> function
			if (computationNeeded == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Cos of " << last << " is " << doMath(last, 'c') << "\n";
						entryCount++;
						break;
					}
					cout << "Cos of " << first + i << " is " << doMath(first + i, 'c') << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "x" || inputCommand == "X")){
			//Compute EXponentials The exp <cmath> function
			if (computationNeeded == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "exponential of " << last << " is " << doMath(last, 'x') << "\n";
						entryCount++;
						break;
					}
					cout << "exponential of " << first + i << " is " << doMath(first + i, 'x') << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "l" || inputCommand == "L")){
			//Compute Natural Logs The log <cmath> function
			if (computationNeeded == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Natural log of " << last << " is " << naturalLog(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Natural log of " << first + i << " is " << naturalLog(first + i) << "\n";
					entryCount++;
				}
			}
	}else if((inputCommand == "y" || inputCommand == "Y")){
			//Compute NYanCat value
			if (computationNeeded == true){
				for(int i = 0; ((i < (last + delta)) && (entryCount < ENTRIES)); i += delta){
					if((i + delta ) > last){
						cout << "Nyancat value of " << last << " is " << findNyanCatValue(last) << "\n";
						entryCount++;
						break;
					}
					cout << "Nyancat value of " << first + i << " is " << findNyanCatValue(first + i) << "\n";
					entryCount++;
				}
			}
	}else{
		cout << "invalid command entered, moving on...." << "\n";
	}		
}
