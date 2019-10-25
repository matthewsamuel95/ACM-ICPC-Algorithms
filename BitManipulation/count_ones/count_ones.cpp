// @author Aureliano Yepez 
// @date Oct 22, 2018

#include <iostream>

using namespace std;

short count_ones(unsigned int x) {
	return __builtin_popcount(x);
}

int main() {

	int number = 10; // use any number
	short result = count_ones(number);
	cout << "result: " << result << endl;
	return 0;
}
