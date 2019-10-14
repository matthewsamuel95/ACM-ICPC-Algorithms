#include <bits/stdc++.h>
using namespace std;
multiset<int> *s[50005],*d[50005];
vector< vector<int> > g(50005);
int color[50005];
int size_tree[50005];
int n,m,ans[500005];

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
        d[u]=d[mv];
    }
    else
    {
        s[u] = new multiset<int>();
        d[u] = new multiset<int>();
        (*s[u]).insert(color[u]);
    }
    for(int i=0;i<g[u].size();i++)
    {
        v= g[u][i];
        if(v==par)
        continue;

        if(v!= mv && v!= par)
        {
            for(auto it=(*s[v]).begin();it!= (*s[v]).end();it++)
            {
                int num = *it;
                auto itt= (*s[u]).lower_bound(num);
                if(itt==(*s[u]).begin())
                {
                    (*s[u]).insert(*it);
                    (*d[u]).insert(abs(*itt-*it));
                }
                else
                if(itt==(*s[u]).end())
                {
                    itt--;
                    (*s[u]).insert(*it);
                    (*d[u]).insert(abs(*itt-*it));
                }
                else
                {
                    int num1=*itt;
                    itt--;
                    int num2=*itt;
                    auto ii=(*d[u]).find(num2-num1);
                    if(ii!=(*d[u]).end())
                    (*d[u]).erase(ii);
                    (*s[u]).insert(*it);
                    (*d[u]).insert(abs(num1-*it));
                    (*d[u]).insert(abs(num2-*it));
                }
            }
        }
    }
    if((*s[u]).size()==1)
    ans[u]=2147483647;
    else
    if(u<(n-m+1))
    ans[u]=*(*d[u]).begin();
    return (int)(*s[u]).size();
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        g[i].push_back(p);
        g[p].push_back(i);
    }

    for(int i=n-m+1;i<=n;i++) scanf("%d",&color[i]);
    int sz=dfs(1,0);
    for(int i=1;i<(n-m+1);i++) printf("%d ",ans[i]);
    return 0;  
}
