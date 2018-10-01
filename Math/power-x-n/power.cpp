#include<iostream.h>

//function to calculate the nth power of x 
float power(int a,int b)
{
  float pro=1;
  for(int i=1;i<=n;i++)
    pro=pro*x;  
  return pro;    
}
void main()
{ 
  float pow = power(x,n);
  std::cout<<x<<" raised to the power "<<n<<" is: "<<pow;
  
  /*
  Exapmles:
  power(2,10)=1024
  power(3,8)=6561
  */
}
