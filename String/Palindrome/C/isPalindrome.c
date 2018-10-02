
#include <stdio.h> 
#include <string.h> 

#define int long long int
#undef int

int isPalindrome(char str[]) 
{ 
    #define int long long int

    int l = 0; 
    int h = strlen(str) - 1; 

    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            printf("%s is Not Palindrome\n", str); 
            return; 
        } 
    } 
    printf("%s is palindrome\n", str); 
} 
  
 
int main() 
{ 
    #define int long long int

    char s[105];
    scanf("%s", s);

    isPalindrome(s);

    return 0; 
}
