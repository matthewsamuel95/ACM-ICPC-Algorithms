#include <bits/stdc++.h>
using namespace std;
map<int,int> *mp[500001];
set<int> *ans[500001];
vector< vector<int> > g(500001);
int want[500001];
int n,h;
long long c=0;
int dfs(int u,int l)
{
    int mx=-1,mv=-1,v;
    for(int i=0;i<g[u].size();i++)
    {
        v= g[u][i]; 
        
        int sz = dfs(v,l+1);
        if(sz>mx)
        {
            mx=sz;
            mv=v;
        }
    }
    if(mx!=-1)
    {
        mp[u]=mp[mv];  
        ans[u]=ans[mv]; 
    }
    else
    {
        mp[u] = new map<int,int>();
        ans[u]= new set<int>();
    }
    (*mp[u])[l]++;
    if(want[l]!=0 && want[l]<=(*mp[u])[l])
    {
        (*ans[u]).insert(l);
    }
    for(long long int i=0;i<g[u].size();i++)
    {
        v= g[u][i];
        if(v!= mv)
        {
            for(auto it=(*mp[v]).begin();it!= (*mp[v]).end();it++)
            {
                (*mp[u])[it->first]+= it->second;
                if(want[it->first] !=0 && want[it->first]<=(*mp[u])[it->first])
                    (*ans[u]).insert(it->first);
            }
        }
    }
    c+= (long long)(*ans[u]).size();
    return (int)(*mp[u]).size();
}

int main()
{
    
    scanf("%d %d",&n,&h);
    
    for(int i=1;i<n;i++)
    {
        int p;
        scanf("%d",&p);
        g[p].push_back(i);
    }

    for(int i=0;i<=h;i++)
    {
        scanf("%d",&want[i]);
        if(want[i]==0)
        c+=n;
    }

    int sz=dfs(0,0);
    
    printf("%lld\n",c);
    return 0;  
}
