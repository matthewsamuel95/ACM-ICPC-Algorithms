#include<iostream>
#include<cmath>
using namespace std;

int nextPowOf2(int n){

	float exp = log2(n);
	int fExp = floor(exp);
	
	if(fExp == exp)return n;
	else return pow(2, fExp + 1); 

}

int main(){

	int n;
	cout << "Enter n : ";
	cin >> n;

	cout << nextPowOf2(n) << endl;
	
	return 0;

}
