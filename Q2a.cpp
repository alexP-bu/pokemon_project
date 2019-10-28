#include <iostream>

using namespace std;

int gcd(int,int);

int main(){
	int m;
	int n;
	int ans;
	
	cout << "Enter m: " << endl;
	cin >> m;
	cout << "Enter n: " << endl;
	cin >> n;
	
	ans = gcd(m,n);
	cout << "GCD is: " << ans; 
	
}

int gcd(int m, int n){
	if(m % n == 0){
		return n;
	}else{
		return gcd(n, m%n);
	}
}