#include <bits/stdc++.h>
using namespace std;
set<int> *s[100005];
vector< vector<int> > g(100005);
int color[100005];
int size_tree[100005];
int dfs(int u,int par)
{
    int mx=-1,mv=-1,v;
    for(int i=0;i<g[u].size();i++)
    {
        v= g[u][i];
        if(v==par)
            continue;
        int sz = dfs(v,u);
        if(sz>mx)
        {
            mx=sz;
            mv=v;
        }
    }
    if(mx!=-1)
    {
        s[u]=s[mv];   
    }
    else
    {
        s[u] = new set<int>();
    }
    (*s[u]).insert(color[u]);


    for(int i=0;i<g[u].size();i++)
    {
        v= g[u][i];
        if(v==par)
        continue;

        if(v!= mv && v!= par)
        {
            for(auto it=(*s[v]).begin();it!= (*s[v]).end();it++)
            {
                (*s[u]).insert(*it);
            }
        }
    }
    return size_tree[u]=(int)(*s[u]).size();
}

int main()
{
    int n,m,r;
    scanf("%d %d %d",&n,&m,&r);
    
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) scanf("%d",&color[i]);
    int sz=dfs(r,0);
    while(m--)
    {
        int d;
        scanf("%d",&d);
        printf("%d\n",size_tree[d]);
    }
    return 0;  
}
