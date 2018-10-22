// @author Aureliano Yepez 
// @date Oct 22, 2018

#include <iostream>

using namespace std; 

short count_ones(unsigned int x) {
	short num_bits = 0; 
	while (x) {
		num_bits += x & 1; // mask one
		x >>= 1; 
	}
	return num_bits; 
}

int main() { 

	int number = 10; // use any number 
	short result = count_ones(number); 
	cout << "result: " << result << endl; 	
	return 0;
}
