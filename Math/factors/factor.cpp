#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
typedef long long ll;

unsigned int primos[MAXN], fatores[MAXN];
vector<bool> is_prime (MAXN, true);
 
void crivo() {
	register unsigned long long i, j, counter = 0;
    primos[counter++] = 2;
 
	for(i=3; i <= MAXN; i += 2) {
		if(is_prime[i]) {
			primos[counter++] = i;
			for(j = i*i; j <= MAXN; j += i) is_prime[j] = false;
		}
	}
}

void primeFactors(ll n) {
	int p = 0;
	ll PF_idx = 0, PF = primos[PF_idx];

	while( PF * PF <= n ) {
		while( n % PF == 0 ) {
			n /= PF;
			fatores[p++] = PF;
		}
		PF = primos[++PF_idx];
		if(not flag) break;
	}

	if(n != 1) fatores[p++] = n;
}

int main(){
  return 0;
}
