#include <iostream>
using namespace std;

int gcd(int a, int b) {

	if (a == 0)
		return b;
	if (b == 0)
		return a;

	int powerOf2;
	for (powerOf2 = 0; ((a | b) & 1) == 0; powerOf2++) {
		a >>= 1;
		b >>= 1;
	}

	while ((a & 1) == 0)
		a >>= 1;

	while (b != 0) {
		while ((b & 1) == 0)
			b >>= 1;
		if (a > b)
			swap(a, b);
		b -= a;
	}
	return a << powerOf2;
}

int main() {

	cout << gcd(258, 321) << endl;
	return 0;
}
