#include <bits/stdc++.h>

#define fastInput ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PB push_back
#define MP make_pair
#define F first
#define S second

#define si(x) int x; scanf("%d", &x)
#define sll(x) ll x; scanf("%lld", &x)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
int A[100005],tree[500005];
void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        A[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start || end < l)
    {
        return 1000000;
    }
    if(l <= start && end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1,p2);
}

int main()
{
  //  cout<<"Welcome to my world"<<endl;

    int n,q,i;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>A[i];
    }

    build(1,1,n);
    for(i=0;i<q;i++)
    {
        char p;
        int l,r;
        cin>>p;
        cin>>l>>r;
        if(p=='q')
        {
            int ans=query(1,1,n,l,r);
            cout<<ans<<endl;
        }
        else
        {
            update(1,1,n,l,r);
        }
    }

    return 0;
}



