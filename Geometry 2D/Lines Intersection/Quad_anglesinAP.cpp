
// C++ implementation of the approach 
#include <bits/stdc++.h> 
#define ll long long int 
using namespace std; 
  
// Driver code 
int main() 
{ 
    int d = 10; 
    double a; 
  
    // according to formula derived above 
    a = (double)(360 - (6 * d)) / 4; 
  
    // print all the angles 
    cout << a << ", " << a + d << ", " << a + (2 * d) 
         << ", " << a + (3 * d) << endl; 
    return 0; 
} 
