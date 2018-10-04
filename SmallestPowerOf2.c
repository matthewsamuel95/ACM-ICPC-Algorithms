#include <stdio.h> 
// Finds next power of two  
// for n. If n itself is a  
// power of two then returns n 
unsigned int nextPowerOf2(unsigned int n) 
{ 
    n--; 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
    n++; 
    return n; 
} 
  
// Driver Code  
int main() 
{ 
    unsigned int n = 5; 
    printf("%d", nextPowerOf2(n)); 
    return 0; 
}      
