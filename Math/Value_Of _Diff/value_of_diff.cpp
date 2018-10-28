#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define MAX 200006 
#define CONS 32766 
  
void calc(ll a[], ll b[], ll lr[], ll q, ll n) 
{ 
    ll M, m, i, j, k, l, r, suma, sumb, cc; 
    cc = 0; 
    for (i = 0; i < n - 1; ++i) { 
        a[i + 1] += a[i]; 
        b[i + 1] += b[i]; 
    } 
  
    while (q--) {  
        l = lr[cc++]; 
        r = lr[cc++]; 
        l -= 2; 
        r -= 1; 
        suma = a[r]; 
        sumb = b[r]; 
        if (l >= 0) { 
            suma -= a[l]; 
            sumb -= b[l]; 
        } 
        M = max(CONS * suma + CONS * sumb, 
                -CONS * suma - CONS * sumb); 
        M = max(M, max(CONS * suma - CONS * sumb, 
                       -CONS * suma + CONS * sumb));  
        m = min(CONS * suma + CONS * sumb, 
                -CONS * suma - CONS * sumb); 
        m = min(m, min(CONS * suma - CONS * sumb, 
                       -CONS * suma + CONS * sumb)); 
  
        cout << (M - m) << "\n"; 
    } 
} 
int main() 
{ 
    ll n = 5, q = 2; 
    ll a[5] = { 0, 7, 3, 4, 5 }; 
    ll b[5] = { 0, 3, 1, 2, 3 }; 
  
    ll lr[q * 2]; 
    lr[0] = 1; 
    lr[1] = 1; 
    lr[2] = 1; 
    lr[3] = 3; 
  
    calc(a, b, lr, q, n); 
  
    return 0; 
} 
