#include <iostream>
#include <cmath>
#define lg2 log (2)
using namespace std;

double getLOG(double n){
  double lgn = log (n);
  double result = lgn / lg2;
  return result;
}

int main(){
  double n;
  cin>>n;
  double result = getLOG(n);
  cout<<result<<endl;
  return 0;
}
