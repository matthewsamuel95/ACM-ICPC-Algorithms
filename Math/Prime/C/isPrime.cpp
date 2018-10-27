#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int x;
	cin >> x;
	if (x == 0 || x == 1) {
		cout << "This number is not prime !\n";
		return 1;
	}
    bool flag = true;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) flag = false;
    flag ? cout << "This number is prime !\n" : "This number is not prime !\n";
}
