/*
	https://www.spoj.com/problems/METEORS
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define MAX 1000000000000000
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revrep(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define ii pair<ll,pair<ll,ll> >
#define MP make_pair
#define pb push_back
#define f first
#define se second
#define ll long long int
#define vi vector<ll>
ll modexp(ll a,ll b){ ll res = 1; while(b > 0){  if(b & 1) res = (res * a)%mod;  a = (a * a)%mod;  b/=2;  }  return res; }
#define rs resize
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > OST;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
 
const ll N = 300009;
ll n,m,i,a,k,s,id;
bool changed = 1;
vector<vi> own,tocheck;
ll lo[N],hg[N],ql[N],r[N],qr[N],qa[N],tr[N];
void update(ll p,ll v)
{
    while(p <= m){
        tr[p] += v;
        p += p & -p;
    }
}
ll read(ll p)
{
    ll s = 0;
    while(p > 0){
        s += tr[p];
        p -= p & -p;
    }
    return s;
}
void apply(ll p)
{
    if(ql[p] <= qr[p]){
        update(ql[p],qa[p]);
        update(qr[p] + 1,-qa[p]);
    }
    else{
        update(1,qa[p]);
        update(qr[p] + 1,-qa[p]);
        update(ql[p],qa[p]);
    }
        
}
int main()
{
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    own.rs(n + 1);
    rep(i,1,m + 1){
        cin>>a;
        own[a].pb(i);
    }
    rep(i,1,n + 1)  cin>>r[i];
    cin>>k;
    tocheck.rs(k + 1);
    rep(i,1,k + 1)  cin>>ql[i]>>qr[i]>>qa[i];
    rep(i,1,n + 1){
        lo[i] = 1;
        hg[i] = k + 1;
    }
    while(changed){
        changed = 0;
        
        //cleaning
        rep(i,0,m + 1) tr[i] = 0;
        rep(i,1,n + 1) if(lo[i] != hg[i])
            tocheck[(lo[i] + hg[i]) / 2].pb(i);
        //end of cleaning
            
        rep(i,1,k + 1){
            apply(i);
            while(tocheck[i].size() > 0){
                changed = 1;
                id = tocheck[i].back();
                tocheck[i].pop_back();
                
                s = 0;
                for(auto &j: own[id]){
                    s += read(j);
                    if(s >= r[id]) break;
                }
                if(s >= r[id])
                    hg[id] = i;
                else
                    lo[id] = i + 1;
            }
        }  
    }
    rep(i,1,n + 1){
        if(lo[i] <= k) cout<<lo[i];
        else
            cout<<"NIE";
        cout<<endl;
    }
    return 0;
} 