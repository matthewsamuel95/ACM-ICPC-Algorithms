// C++ program to check  
// similarity between  
// two triangles. 
#include<bits/stdc++.h> 
using namespace std; 
  
//Function for AAA similarity 
int simi_aaa(int a1[], int a2[]) 
{ 
    sort(a1, a1 + 3); 
    sort(a2, a2 + 3); 
      
    // Check for AAA 
    if (a1[0] == a2[0] &&  
        a1[1] == a2[1] &&  
        a1[2] == a2[2]) 
    return 1; 
    else
    return 0; 
      
} 
  
// Function for 
// SAS similarity 
int simi_sas(int s1[], int s2[],  
             int a1[], int a2[]) 
{ 
    sort(a1, a1 + 3); 
    sort(a2, a2 + 3); 
    sort(s1, s1 + 3); 
    sort(s2, s2 + 3); 
      
    // Check for SAS 
      
    // angle b / w two smallest 
    // sides is largest. 
    if( s1[0] / s2[0] == s1[1] /  
                         s2[1]) 
    { 
        // since we take angle 
        // b / w the sides. 
        if (a1[2] == a2[2])          
            return 1; 
    } 
    if (s1[1] / s2[1] == s1[2] / 
                         s2[2]) 
    { 
        if (a1[0] == a2[0]) 
            return 1; 
        }  
    if (s1[2] / s2[2] == s1[0] /     
                         s2[0]) 
    { 
        if(a1[1] == a2[1]) 
            return 1; 
        } 
    return 0; 
} 
  
// Function for SSS similarity 
int simi_sss(int s1[], int s2[]) 
{ 
    sort(s1, s1 + 3); 
    sort(s2, s2 + 3); 
      
    // Check for SSS 
    if(s1[0] / s2[0] == s1[1] / s2[1] &&  
       s1[1] / s2[1] == s1[2] / s2[2] &&  
       s1[2] / s2[2] == s1[0] / s2[0]) 
        return 1; 
      
    return 0; 
} 
  
// Driver Code 
int main() 
{ 
    int s1[] = {2, 3, 3}; 
    int s2[] = {4, 6, 6}; 
          
    int a1[] = {80, 60, 40}; 
    int a2[] = {40, 60, 80}; 
  
    // function call for 
    // AAA similarity 
    int aaa = simi_aaa(a1, a2);  
  
    // function call for 
    // SSS similarity  
    int sss = simi_sss(s1, s2) ; 
  
    // function call for 
    // SAS similarity  
    int sas = simi_sas(s1, s2,  
                       a1, a2) ; 
  
    // Check if triangles 
    // are similar or not  
    if(aaa == 1 ||  
       sss == 1 || sas == 1) 
    { 
        cout << "Triangles are " 
             << "similar by "; 
        if(aaa == 1) cout << "AAA "; 
        if(sss == 1) cout << "SSS "; 
        if(sas == 1) cout << "SAS."; 
    } 
      
    else
        cout << "Triangles are " 
             << "not similar"; 
    return 0; 
}
