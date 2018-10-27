#include <bits/stdc++.h>

void isPrime(int a){
	if (x == 0 || x == 1) {
		cout<<"This number is not prime !\n";
		return;
	}
	int f = 1;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) f = 0;
	if (f) cout<<"This number is prime !\n";
	else cout<<"This number is not prime !\n";
}

int main() {
	int x;
	cin>>x;
	isPrime(x);
	return 0;
}
