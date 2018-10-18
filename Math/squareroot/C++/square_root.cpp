#include<iostream>
#include<math.h>
using namespace std;

int sqrt(int x)
{
  if(x==0) return 0;

  int counter=1;
  while(pow(counter,2)<=x){
    counter++;
  }
  counter--;
  return counter;
}
int main()
{
  int n;
  cout<<"Enter Number\n";
  cin>>n;
  cout<<"The square root of the number is: "<<sqrt(n)<<endl;
  return 0;
}
