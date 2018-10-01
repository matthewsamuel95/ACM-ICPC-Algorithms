//C++ Implementation - Square Root of an Integer
#include<iostream> 
#include<cmath>
using namespace std;

int foo(float n) 
{ 
 
  float x = n; 
  float y = 1; 
  float e = 0.000001; 
  while(x - y > e) 
  { 
    x = (x + y)/2; 
    y = n/x; 
  } 
  return floor(x); 
} 
  
int main() 
{ 
  float num;
  cin>>num;
  cout<<foo(num);
} 