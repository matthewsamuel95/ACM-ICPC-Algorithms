// CPP program to find 
// perimeter of cylinder 
#include <iostream> 
using namespace std; 

// Function to calculate perimeter 
int perimeter(int diameter, int height) 
{ 
	return 2 * (diameter + height); 
} 

// Driver function 
int main() 
{ 
	int diameter = 5; 
	int height = 10; 
	
	cout << "Perimeter = "; 
	cout<< perimeter(diameter, height); 
	cout<<" units\n"; 
	
	return 0; 
} 

