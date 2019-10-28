#include <iostream>

using namespace std;

double series(int);

int main(){
	double n;
	double ans;
	
	cout << "Enter n: " << endl;
	cin >> n;
	
	ans = series(n);
	cout << "Series(" << n << ") is: " << ans; 
	
}

double series(int n){
	if(n == 1){
		//2/5
		return 0.4;
	}else{
		//needed to cast to double otherwise it only shows one decimal
		double output = (double)(2*n)/((3*n)+2);
		//return next term of the series until its 0.4
		return (output + series(n-1));
	}
}