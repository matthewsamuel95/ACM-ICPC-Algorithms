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

/*
	http://codeforces.com/contest/706/problem/D
*/
const ll N = 200009,M = 32;
ll a,q;
char c;
struct node
{
    ll c;
    node* ptr[2];
};
node* getnode()
{
    node* nxt = new node();
    nxt->c = 0;
    nxt->ptr[0] = nxt->ptr[1] = NULL;
    return nxt;
}
void operate(ll no,ll add,node* root)
{
    node* head = root;
    for(ll i = M;i >= 0;i--){
        ll d = (no >> i) & 1;
        if(head->ptr[d] == NULL)
            head->ptr[d] = getnode();
        head = head->ptr[d];
        head->c += add;
    }
}
ll max_xor(ll no,node* root)
{
    node* head = root;
    ll ans = 0;
    for(ll i = M;i >= 0;i--){
        ll d = (no >> i) & 1;
        if(head->ptr[1 - d] != NULL and head->ptr[1 - d]->c > 0){
            ans += (1 << i);
            head = head->ptr[1 - d];
        }
        else
            head = head->ptr[d];
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    node* TRIE = getnode();
    operate(0,1,TRIE);
    cin>>q;
    while(q--){
        cin>>c>>a;
        if(c == '+') operate(a,1,TRIE);
        else{
            if(c == '-') operate(a,-1,TRIE);
            else
                cout<<max_xor(a,TRIE)<<endl;
        }
    }
    return 0;
}