
#include<iostream>

using namespace std;

float power(float x, int y) 
{ 
	float temp; 
	if( y == 0) 
	return 1; 
	temp = power(x, y/2);	 
	if (y%2 == 0) 
		return temp*temp; 
	else
	{ 
		if(y > 0) 
			return x*temp*temp; 
		else
			return (temp*temp)/x; 
	} 
} 

/* Program to test function power */
int main() 
{ 
    
	float x;
	cin>>x;
	int y ;
	cin>>y;
	printf("%f", power(x, y)); 
	return 0; 
} 

