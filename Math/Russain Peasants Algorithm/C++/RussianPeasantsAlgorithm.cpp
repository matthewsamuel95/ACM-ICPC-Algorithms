#include <iostream>
using namespace std;

int multiply(int a, int b)
{
	int prod = 0;
	while (b > 0)
	{
		if (b % 2 != 0)
		{
 			prod += a;
		}
		a = a << 1; // multiply by 2
		b = b >> 1; // divide by 2
	}

	return prod;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << multiply(a, b) << endl;

	return 0;
}
