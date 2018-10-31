#include <bits/stdc++.h>
using namespace std;
int isPalindrome(string s) 
{ 
    return reverse(s.begin(), s.end())==s;
} 
  
int main() 
{ 
    string s;
    cin>>s;
    isPalindrome(s);
    return 0; 
}
