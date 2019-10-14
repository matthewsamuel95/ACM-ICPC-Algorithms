#include<iostream>
#include<cmath> 
using namespace std;


//avoids the space complexity of O(n) by directly extracting the digits from the input.
bool IsPalindromeNumber(int x) {
  if (x <= 0) {
    return x == 0;
  }

  const int num_digits = static_cast<int>(floor(log10(x))) + 1;
  int msd_mask = static_cast<int>(pow(10, num_digits - 1));
  for (int i = 0; i < (num_digits / 2); ++i) {
    if (x / msd_mask != x % 10) { //checks MSB != LSB returns false
      return false;
    }
    x %= msd_mask;  // Remove the most significant digit of x.
    x /= 10;        // Remove the least significant digit of x.
    msd_mask /= 100;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  if(IsPalindromeNumber(n)) cout<<"Palindrome";
  else cout<<"Not Palindrome";
  return 0;
}
