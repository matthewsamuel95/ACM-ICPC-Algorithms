#include <iostream>
#include <cmath>
using namespace std;

// Find the maximum number with d digits that can be divisible by m
// Example
// m = 4, d = 3, ans = 996
// m = 3, d = 3, ans = 999
// m = 9, d = 3, ans = 999
// m = 2, d = 7, ans = 9999998

int main() {
  int m, d;

  cin >> m >> d;
  long int max_num = pow(10, d)-1;
  cout << max_num - max_num%m << endl;
}
