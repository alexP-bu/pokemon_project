#include <iostream>

using namespace std;

int* reverseMultiply(int*, int);

int main(){
	int size = 5;
	int a[size] = {1,2,3,4,5};
	//reverseMulitply B
	int* b = reverseMultiply(a,size);
	for (int i = 0; i<9; i++){
		cout << b[i];
	}
	
}

int* reverseMultiply(int* list, int size){
	int newSize = (int)(size*2) + 1;
	
	int newArray[newSize];
	//load old values into new array 
	for(int i = 0; i < size; i++){
		newArray[i] = list[i];
	}
	//load them in backwards again
	int temp = size;
	for(int i = size; i < size*2; i++){
		newArray[i] = list[temp];
		temp--;
	}
	//now find their product
	int product = 1;
	for(int i = 0; i < newSize; i++){
		product *= newArray[i];
	}
	
	//put product in last 
	newArray[newSize - 1] = product;
	return newArray;
}