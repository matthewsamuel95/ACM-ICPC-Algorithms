#include <bits/stdc++.h> 
using namespace std; 
 
int nthMagicNo(int n) 
{ 
    int pow = 1, answer = 0; 

    
    while (n) 
    { 
    pow = pow*5; 

     
    if (n & 1) 
        answer += pow; 

    
    n >>= 1;
    } 
    return answer; 
} 

int main() 
{ 
    int n;
    cin>>n;
    cout << "nth magic number is " << nthMagicNo(n) << endl; 
    return 0; 
} 
