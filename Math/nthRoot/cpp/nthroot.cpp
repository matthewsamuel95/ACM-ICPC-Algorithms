```cpp

#include<iostream>
#include<math.h>

using namespace std;

double nthroot(int b,int n)
{

  return pow(b,-n);
    
}

int main()
{

  int b,n;
  
  cout<<"Enter the number whose nth root is to be calculated: ";
  cin>>b;
  
  cout<<"Enter the exponent n for the nth root: ";
  cin>>n;
  
  cout<<"The "<<n<<"th root of "<<b<<" is equal to "<<nthroot(b,n);

  return 0;

}

```
