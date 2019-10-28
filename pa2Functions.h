#ifndef PA2FUNCTIONS_H
#define PA2FUNCTIONS_H
using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <sstream>
#include <cstdlib>

//function prototypes
void initialize();
bool checkCode(string);
int factorial(int);
int fibonacci(int);
double findSqrtValue(double);
double naturalLog(double);
double areaCircle(double);
double areaSquare(double);
void writeDataToFile(const char *);
int findNextOddValue(int);
int findNextEvenValue(int);
double findNyanCatValue(double);
double doMath(double, char);
double lucky(double);
void readDataFromFile(const char *);


//my own function prototypes to make my life easier
//get user input gets user values and checks ahead of time if compuation is needed
bool getUserInput(double *,double *,double *);
bool getUserInput(double *,double *);
void getUserInput(double *);
string getCommandName(string);
void runCommand(string);
void runCommand(string, double);
void runCommand(string, double, double);
void runCommand(string, double, double, double);
#endif