

#include<iostream> 
using namespace std; 
  

int isPalindrome(int n) 
{ 

    int rev = 0; 
    for (int i = n; i > 0; i /= 10) 
        rev = rev*10 + i%10; 
  

    return (n==rev); 
} 
  

void countPallindrome(int min, int max) 
{ 
    for (int i = min; i <= max; i++) 
        if (isPalindrome(i)) 
          cout << i << " "; 
} 
  

int main() 
{ 
    countPallindrome(100, 2000); 
    return 0; 
} 
