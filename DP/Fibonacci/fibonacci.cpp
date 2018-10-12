#include<bits/stdc++.h>
using namespace std;

int f[100005]={0};
f[0] = 1;
f[1] = 1;

int fib(int n)
{
  if(f[n]) return f[n];
  else return(f[n-1] +f[n-2]);
}

int main()
{
  int n;
  cout<<"Enter the no who finonacci is to be found : ";
  cin>>n;
  cout<<"Fibonacci of "<<n<< "is :"fib(n);

return 0;
}
