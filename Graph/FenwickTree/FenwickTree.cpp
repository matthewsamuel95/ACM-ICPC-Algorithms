#include<bits/stdc++.h>

using namespace  std;
#define mx 100009
typedef long long int ll;
int arr[mx];
int bit[mx];
int n,m;
void update(int index,ll  val)
{
    index+=1;
    while(index<=n)
    {
        bit[index]+=val;
        index += index & (-index);

    }

}
ll getsum(int index)
{
    ll sum=0;
    index+=1;
    while(index>0)
    {
        //cout<<index<<" "<<bit[index]<<endl;
        sum+=bit[index];
        index-=index&(-index);
    }
    return sum;
}
int main()
{

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    memset(bit,0,sizeof bit);
    for(int i=0;i<n;i++)
    {
        update(i,arr[i]);
    }
    int x,y,t;


    while(m--)
    {

        cin>>t;
        if(t==1)
        {
            cin>>x>>y;
            ll diff=y-arr[x];
            update(x,diff);
            arr[x]=y;
        }
        else
        {
            cin>>x;

            cout<<getsum(x)<<endl;
        }
    }
    return 0;
}
