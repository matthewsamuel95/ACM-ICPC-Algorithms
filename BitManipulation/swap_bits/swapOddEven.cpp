// C program to swap even and  
// odd bits of a given number 
#include <bits/stdc++.h> 
using namespace std;
  
// Function to swap even 
// and odd bits 
unsigned int swapBits(unsigned int x) 
{ 
    // Get all even bits of x 
    unsigned int even_bits = x & 0xAAAAAAAA;  
  
    // Get all odd bits of x 
    unsigned int odd_bits  = x & 0x55555555;  
  
    even_bits >>= 1;  // Right shift even bits 
    odd_bits <<= 1;   // Left shift odd bits 
  
    return (even_bits | odd_bits); // Combine even and odd bits 
} 
  
// Driver program to test above function 
int main() 
{ 
    unsigned int x;
     // 00010111 
    cin>>x;
  
    // Output is 43 (00101011) 
    printf("%u ", swapBits(x)); 
  
    return 0; 
}