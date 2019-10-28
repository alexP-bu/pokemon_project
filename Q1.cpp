#include "pa2Functions.h"
using namespace std;
extern const int ENTRIES = 10;
int entryCount = 0;
string* inputPtr;
bool writing = false;

int main(){
	//intialize it
	string inputCommand;
	initialize();
	//begin loop for program
	while(entryCount <= ENTRIES){
		//initialize some variables and pointers for future use
		string fileName;
		inputPtr = &inputCommand;
		//get input command
		cout << "Please enter command code: ";
		cin >> inputCommand;
		//check if input command is valid
		while(checkCode(inputCommand) == false){
			cout << "Invalid code entered!" << "\n";
			cout << "Please enter valid command code: ";
			cin >> inputCommand;
		}
		//whats the command supposed to do?
		//everything is done in a function to make it easy
		cout << "You selected the " << getCommandName(inputCommand) << " function." << "\n";
		//quit write or read?
		if(((inputCommand == "q") || (inputCommand == "Q")) || entryCount >= ENTRIES){
			//Quit program
			break;
		}else if((inputCommand == "i" || inputCommand == "I")){
			//read from file
			cout << "enter filename: " << "\n";
			cin >> fileName;
			readDataFromFile(fileName.c_str());
		}else if((inputCommand == "o" || inputCommand == "O")){
			//Write to Output file
			cout << "enter filename: " << "\n";
			writeDataToFile(fileName.c_str());
		}else{
			//just run the command!
			runCommand(inputCommand);
		}
	}
	cout << "Program has quit! Either too many entries or quit command was entered." << "\n";
	return 0;
}