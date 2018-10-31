#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000

typedef long long ll;



ll k;
vector<ll> a,b,c;

vector<vector<ll> > multiply(vector<vector<ll> > M1 , vector<vector<ll> > M2)
{
	vector<vector<ll> > M3(k+1,vector<ll>(k+1,0));
	
	for(ll i=1;i<=k;i++){
		
		for(ll j=1;j<=k;j++)
		{
			for(ll x=1;x<=k;x++)
			{
				M3[i][j]=(M3[i][j]+(M1[i][x]*M2[x][j])% MOD)%MOD;
			}
		}
	}
	return M3;
	
}

vector<vector<ll> > power(vector<vector<ll> > M1, ll n)
{
	vector<vector<ll> > ANS(k+1,vector<ll>(k+1,0));
	
	for(ll i=0;i<=k;i++)
	{
		ANS[i][i]=1;
	}
	
	while(n)
	{
		if(n&1)
		ANS=multiply(ANS,M1);
		M1=multiply(M1,M1);
		n>>=1;
		
	}
	return ANS;
}


ll compute(ll n){
	if(n==0)
	return 0;
	if(n<=k)
	return b[n-1];
	
	vector<ll> F1(k+1,0);
	for(ll i=1;i<=k;i++)
	F1[i]=b[i-1];
	
	vector<vector<ll> > T(k+1,vector<ll>(k+1,0));
	
	for(ll i=1;i<k;i++)
	{
		for(ll j=1;j<=k;j++)
		{
			if(j==i+1)
			T[i][j]=1;
			else
			T[i][j]=0;
		}
	}
	
	for(ll i=1;i<=k;i++)
	T[k][i]=c[k-i];
	
	T=power(T,n-1);
	
	ll res=0;
	
	for(ll i=1;i<=k;i++)
	{
		res= (res + (T[1][i]*F1[i]))%MOD;
	}
	
	return res;
	
}
int main() {
	
	ll x;
	ll n;
	cin>>k;
	
	for(ll i=0;i<k;i++)
	{
		cin>>x;
		b.push_back(x);
	}
	
	for(ll i=0;i<k;i++)
	{
		cin>>x;
		c.push_back(x);
	}
	cin>>n;
	cout<<compute(n)<<endl;
	
	b.clear();
	c.clear();
	
	return 0;
}
