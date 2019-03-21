#include<bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
  
// function to find gcd of two integer numbers 
ll gcd(ll a, ll b) 
{ 
    if (!a) 
       return b; 
    return gcd(b%a,a); 
} 
  
// Here 'a' is integer and 'b' is string. 
// The idea is to make the second number (represented 
// as b) less than and equal to first number by 
// calculating its mod with first integer number 
// using basic mathematics 
ll reduceB(ll a, char b[]) 
{ 
    // Initialize result 
    ll mod = 0; 
  
    // calculating mod of b with a to make 
    // b like 0 <= b < a 
    for (int i=0; i<strlen(b); i++) 
        mod = (mod*10 + b[i] - '0')%a; 
  
    return mod; // return modulo 
} 
  
// This function returns GCD of 'a' and 'b' 
// where b can be very large and is represented 
// as a character array or string 
ll gcdLarge(ll a, char b[]) 
{ 
    // Reduce 'b' (second number) after modulo with a 
    ll num = reduceB(a, b); 
  
    // gcd of two numbers 
    return gcd(a, num); 
} 
  
// Driver program 
int main() 
{ 
    // first number which is integer 
    ll a = 1221; 
  
    // second number is represented as string because 
    // it can not be handled by integer data type 
    char b[] = "1234567891011121314151617181920212223242526272829"; 
  
    cout << gcdLarge(a, b); 
  
    return 0; 
} 
