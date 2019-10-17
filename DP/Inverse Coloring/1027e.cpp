// http://codeforces.com/problemset/problem/1027/E
// E. Inverse Coloring

//$ time g++ -c -std=c++11 vec.cpp -fconstexpr-depth=600
//7keyet el STACK hethi work only on windows based sys. like CF; no need to change stack size on ACM/Kattis judge
//#pragma comment(linker, "/STACK:36777216")
//OPT COMPILER:global compiler c++11
//Lex MOD-0 ver. 2.4 (06/08/2018)
//la ilaha illallah
//{
#include<bits/stdc++.h>
#define ll                  long long
#define rep(i,n)            for(auto i=0;i<(n);++i)
#define pb                  push_back
#define mp                  make_pair
#define ff                  first
#define ss                  second
#define sz(v)               v.size()
#define all(v)              std::begin(v), std::end(v)
#define vi                  vector<int>
#define mod                 1000000007LL

#define StringToInt(s,n)    if ( ! (istringstream(s) >> n) ) n = 0;
using namespace std;
template <typename T>
string NumberToString ( T Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef ONLINE_JUDGE
#define line
#define o(x)
#else
#define line                cerr<<'\n';
#define o(x)				cerr << __LINE__ << " $" << #x << " = " << x << "\n";
#endif // ONLINE_JUDGE

ll qpow(ll p,ll q)
{
    ll f=1;
    while(q) {
        if(q&1)
            f=f*p%mod;
        p=p*p%mod;
        q>>=1;
    }
    return f;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-')
            f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
//}


const ll mod7=998244353LL;
inline ll add(ll _x, ll _y, ll _mod=mod7)
{
    _x+=_y;
    return _x>=_mod ? _x-_mod : _x;
}
inline ll sub(ll _x, ll _y, ll _mod=mod7)
{
    _x-=_y;
    return _x<0 ? _x+_mod : _x;
}
inline ll mul(ll _x, ll _y,ll _mod=mod7)
{
    _x*=_y;
    return _x>=_mod ? _x%_mod : _x;
}



int const N = 553;
ll t[N][N], cum[N][N];
#define after (in-ik-before)
int main()
{
#ifndef ONLINE_JUDGE
//freopen("a.txt", "r", stdin);
#endif // ONLINE_JUDGE
//preprocessing
    rep(ik,501) cum[0][ik] = 1LL;
    for(int in=1; in<=500; ++in) {
        for(int ik=1; ik<=in; ++ik) {
            for(int before=0; after>=0; ++before) {
                t[in][ik] = add( t[in][ik], mul(cum[before][min(before,ik-1)], cum[after][min(after,ik)] ));
            }
            cum[in][ik] = add(cum[in][ik-1],  t[in][ik] );
        }
    }

    int n,k;
    cin>>n>>k;
    ll sol = 0LL;

    for(int a=1; a<min(k,n+1); ++a) {
			if (k%a==0)
				sol = add( sol, mul(t [n][a], cum[n][min(n,(k-1)/a)] ));
			else
				sol = add( sol, mul(t [n][a], cum[n][min(n,k/a)] ));
    }


	//on ne peut pas factoriser le calcul des mat transposées
    cout<<mul(sol,2LL);// x2, "Inverse Coloring" ^^
    return 0;
}
