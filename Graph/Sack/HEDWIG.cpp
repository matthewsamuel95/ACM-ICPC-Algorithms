#include <bits/stdc++.h>
using namespace std;
map<int,int> *freq[200005];
map<int,int> *counter[200005];
vector< vector<int> > g(200005);
int color[200005];
int fav[200005];
int ans[200005];
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
        freq[u]=freq[mv];
        counter[u]=counter[mv];   
    }
    else
    {
        freq[u] = new map<int,int>();
        counter[u] = new map<int,int>();
    }

    if((*freq[u]).find(color[u]) != (*freq[u]).end())
    {
        (*counter[u])[(*freq[u])[color[u]]]--;    
        if((*counter[u])[(*freq[u])[color[u]]]==0)
        {
           (*counter[u]).erase((*freq[u])[color[u]]);
        }
        (*freq[u])[color[u]]++;
        (*counter[u])[(*freq[u])[color[u]]]++;
    }
    else
    {
        (*freq[u])[color[u]]++;
        (*counter[u])[(*freq[u])[color[u]]]++;
    }
    for(int i=0;i<g[u].size();i++)
    {
        v= g[u][i];
        if(v==par)
        continue;
        if(v!= mv && v!= par)
        {
            for(auto it=(*freq[v]).begin();it!= (*freq[v]).end();it++)
            {
                if((*freq[u]).find(it->first) != (*freq[u]).end())
                {
                    (*counter[u])[(*freq[u])[it->first]]--;
                    if((*counter[u])[(*freq[u])[it->first]]==0)
                    {
                        (*counter[u]).erase((*freq[u])[it->first]);
                    }
                    (*freq[u])[it->first] += it->second;
                    (*counter[u])[(*freq[u])[it->first]]++;
                }
                else
                {
                    (*freq[u])[it->first] = it->second;
                    (*counter[u])[it->second]++;
                }
            }
        }

    }
    if((*counter[u]).find(fav[u]) != (*counter[u]).end())
    ans[u]= (*counter[u])[fav[u]];
    return (int)(*freq[u]).size();
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&color[i]);
    for(int i=1;i<=n;i++) scanf("%d",&fav[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int sz=dfs(1,0);
    for(int i=1;i<=n;i++)
    printf("%d\n",ans[i]);
    return 0;  
}
