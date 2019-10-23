//C++ program to compute lcm of two numbers

#include <iostream>
using namespace std;

//Euclidean gcd algorithm to compute gcd of two numbers in log(n) time complexity
int gcd(int a, int b)
{
    if(b == 0) 
    {
        return a;
    }
    return gcd(b, a%b);
}

//Using the mathematical property that lcm(a,b) = (a*b)/gcd(a,b)
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int a,b;
    cin>>a>>b;

    cout<<lcm(a,b);
}