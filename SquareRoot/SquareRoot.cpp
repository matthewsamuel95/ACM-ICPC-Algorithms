//C++ Implementation - Square Root of an Integer
#include<bits/stdc++.h> 
using namespace std; 
  
int foo(int x) 
{ 
    if (x == 0 || x == 1) 
    return x; 
    int i = 1, result = 1; 
    while (result <= x) 
    { 
      i++; 
      result = i * i; 
    } 
    return i - 1; 
} 
  
// Main function 
int main() 
{ 
    int num;
    cin>>num;
    cout << foo(num) << endl; 
    return 0; 
} 