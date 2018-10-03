#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mult(ll a, ll b, ll m){
    return ((a%m)*(b%m))%m;
}

ll fast_exp_mod(ll b, ll e, ll m){
    if(e == 0) return 1;
    if(e == 1) return b%m;
    if(e % 2 == 0){
        ll x = fast_exp_mod(b, e>>1, m);
        return mult(x,x,m);
    }
    return mult(fast_exp_mod(b, e-1, m), b, m);
}

int main(){
    ll b, e, m;
    scanf("%lld%lld%lld", &b, &e, &m);
    printf("%lld\n", fast_exp_mod(b, e, m));
    return 0;
}
