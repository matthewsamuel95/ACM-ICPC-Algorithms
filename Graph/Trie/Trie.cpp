//TRIE
#include <bits/stdc++.h>
using namespace std;
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d%d",&x,&y)
#define siii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld%lld",&x,&y)
#define slll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
 
#define ll long long
#define mp make_pair
#define pb push_back
#define nl printf("\n");
#define pf printf
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define vint vector<int>
#define tci int t;scanf("%d",&t);while(t--)
const int maxn=10e6+4;

struct Trie{
    struct Trie *child[27];
    map<char ,Trie*>m;
    int w;
};
struct Trie *getNode(void)
{
    struct Trie *p =  new Trie;
    p->w = 0;
    for (int i = 0; i < 27; i++)
        p->child[i] = NULL;
    return p;
}


int res=0;
int rec(struct Trie *p)
{
    for(int i=0;i<27;i++)
    {
        if(p->child[i]!=NULL)
        {
            res= max(rec(p->child[i]),res);
        }
    }
    return p->w;
}

void insert(struct Trie *root,string s,int weight)
{
    struct Trie *p=root;
    for(int i=0;i<s.size();i++)
    {
        int ind=int(s[i]-'a');
        if(p->child[ind]==0)
            p->child[ind]=getNode();
        p=p->child[ind];
    }
    p->w=weight;
    //cout<<p->w;nl
}
void search(struct Trie *root,string s)
{
    int temp=0;
    struct Trie *p = root;
    for (int i = 0; i < s.size(); i++)
    {
        int ind = s[i] - 'a';
        //cout<<s[i]<<" ";
        if (!p->child[ind])
        {    
            temp=1;
            cout<<-1<<endl;break;//return false;
        }
        p = p->child[ind];
    }
    if(p != NULL && !temp )
    {
        rec(p);
        cout<<res;nl
    }
}
int main()
{
    ifstream myFile("task.in");
    if(!myFile.fail())
    {
        assert(freopen("task.in", "r", stdin));
    }
    struct Trie *root=getNode();
    int n,q;sii(n,q);
    rep(i,n)
    {
        string s;
        int weight;
        cin>>s>>weight;
        insert(root,s,weight);
    }
    while(q--)
    {
        res=0;
        string s;
        cin>>s;
        search(root,s);
    }
    return 0;
}
