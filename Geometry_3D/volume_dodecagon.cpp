// CPP program to calculate 
// Volume of dodecahedron 
#include <bits/stdc++.h> 
using namespace std; 

// utility Function 
double vol_of_dodecahedron(int side) 
{ 
	return (((15 + (7 * (sqrt(5)))) / 4) 
					* (pow(side, 3))) ; 
} 
// Driver Function 
int main() 
{ 
	int side = 4; 
	
	cout << "Volume of dodecahedron = "
		<< vol_of_dodecahedron(side); 
} 

