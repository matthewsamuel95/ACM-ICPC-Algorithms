#include <bits/stdc++.h>
using namespace std;
#define N 100000
int a[N+1],tree[N+1][17];
void build(int n)
{
    for(int i=1;i<=n;i++)
        tree[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            tree[i][j]=min(tree[i][j-1],tree[i+(1<<(j-1))][j-1]);
        }
    }
}
int que(int l,int r)
{
   int k=(int)log2(r-l+1);
   return min(tree[l][k],tree[r-(1<<k)+1][k]);
}
int main()
{
    int t,n,q,l,r,k=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(n);
        printf("Scenario #%d:\n",k++);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",que(l,r));
        }
    }
}
