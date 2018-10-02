#include<iostream>
using namespace std;
float power(float x, int y) {
  float res = 1;
  while(y>0) {
    if(y&1)
      res = res*x;
    y>>=1;
    x = x*x;
  }
  return res;
}
int main() {
  float x;
  int y;
  cin>>x>>y;
  cout<<power(x, y)<<endl;
}
