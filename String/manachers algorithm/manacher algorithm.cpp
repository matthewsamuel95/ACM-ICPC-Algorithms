#include <stdio.h> 
#include <string.h> 
  
char text[100]; 
int min(int a, int b) 
{ 
    int res = a; 
    if(b < a) 
        res = b; 
    return res; 
} 
  
void findLongestPalindromicString() 
{ 
    int N = strlen(text); 
    if(N == 0) 
        return; 
    N = 2*N + 1; //Position count 
    int L[N]; //LPS Length Array 
    L[0] = 0; 
    L[1] = 1; 
    int C = 1; //centerPosition  
    int R = 2; //centerRightPosition 
    int i = 0; //currentRightPosition 
    int iMirror; //currentLeftPosition 
    int maxLPSLength = 0; 
    int maxLPSCenterPosition = 0; 
    int start = -1; 
    int end = -1; 
    int diff = -1; 
      
    //Uncomment it to print LPS Length array 
    //printf("%d %d ", L[0], L[1]); 
    for (i = 2; i < N; i++)  
    { 
        //get currentLeftPosition iMirror for currentRightPosition i 
        iMirror  = 2*C-i; 
        L[i] = 0; 
        diff = R - i; 
        //If currentRightPosition i is within centerRightPosition R 
        if(diff > 0) 
            L[i] = min(L[iMirror], diff); 
  
        //Attempt to expand palindrome centered at currentRightPosition i 
        //Here for odd positions, we compare characters and  
        //if match then increment LPS Length by ONE 
        //If even position, we just increment LPS by ONE without  
        //any character comparison 
        while ( ((i + L[i]) < N && (i - L[i]) > 0) &&  
            ( ((i + L[i] + 1) % 2 == 0) ||  
            (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))) 
        { 
            L[i]++; 
        } 
  
        if(L[i] > maxLPSLength)  // Track maxLPSLength 
        { 
            maxLPSLength = L[i]; 
            maxLPSCenterPosition = i; 
        } 
  
        //If palindrome centered at currentRightPosition i  
        //expand beyond centerRightPosition R, 
        //adjust centerPosition C based on expanded palindrome. 
        if (i + L[i] > R)  
        { 
            C = i; 
            R = i + L[i]; 
        } 
        //Uncomment it to print LPS Length array 
        //printf("%d ", L[i]); 
    } 
    //printf("\n"); 
    start = (maxLPSCenterPosition - maxLPSLength)/2; 
    end = start + maxLPSLength - 1; 
    printf("LPS of string is %s : ", text); 
    for(i=start; i<=end; i++) 
        printf("%c", text[i]); 
    printf("\n"); 
} 
  
int main(int argc, char *argv[]) 
{ 
  
    strcpy(text, "babcbabcbaccba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abaaba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abababa"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abcbabcbabcba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "forgeeksskeegfor"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "caba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abacdfgdcaba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abacdfgdcabba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abacdedcaba"); 
    findLongestPalindromicString(); 
  
    return 0; 
} 