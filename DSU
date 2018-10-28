#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
    //ll value;
    node* parent;
    ll depth;
    //bool isroot;
    ll sizethis;
};

map<ll,node*>mapped;

void buildset(ll n,ll ar[])
{
    for(ll i=1;i<=n;i++)
    {
        node* temp = new node;
        temp->depth=0;
        temp->parent=temp;
        //temp->value=ar[i];
        //temp->isroot=true;
        temp->sizethis=1;

        mapped[ar[i]]=temp;
    }
}
node* findset(ll n)
{
    node* temp= mapped[n];

    while(temp->parent!=temp)
    {

        temp=temp->parent;

    }
    return temp;
}
void unionset(ll a,ll b)
{
    node* temp1 = findset(a);
    node* temp2 = findset(b);
    if(temp1==temp2)
        return;

    if(temp1->depth>temp2->depth)
    {

        temp2->parent=temp1;
        //temp2->isroot=false;
        temp1->sizethis+=temp2->sizethis;


    }
    else
    {
        temp1->parent=temp2;
        temp2->depth++;
        //temp1->isroot=false;
        temp2->sizethis+=temp1->sizethis;

    }
}
int main()
{

       ll n,m;
       scanf("%lld %lld",&n,&m);
       ll ar[n+1];
       for(ll i=1;i<=n;i++)
       ar[i]=i;
       buildset(n,ar);

       ll a,b;
       for(ll i=1;i<=m;i++)
       {
            scanf("%lld %lld",&a,&b);
           unionset(a,b);

       }
       for(ll i=1;i<=n;i++)
       {

           cout << findset(i)->sizethis-1 << " ";
       }
    return 0;
}
