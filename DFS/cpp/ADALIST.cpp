#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    while(q--)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int k,x;
            cin>>k>>x;
            v.insert(v.begin()+k-1,x);
        }
        if(a==2)
        {
            int x;
            cin>>x;
            v.erase(v.begin()+x-1);
        }
        if(a==3)
        {
            int x;
            cin>>x;
            cout<<v[x-1]<<endl;
        }
    }
    return 0;
}
