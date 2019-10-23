#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<ll> level[10000];
void print(vector<vector<ll> > p,ll i,ll j,ll* a,ll l)     //print function
{
    if(i>j) return ;

    print(p,i,p[i][j]-1,a,l+1);             //recursion go to left side
    level[l].push_back(a[p[i][j]]);
    print(p,p[i][j]+1,j,a,l+1);             //recursion go to right side
}

int main()
{
    ll n;
    cin >>n;
    pair<ll,ll> a[n];
    ll b[n];
    for(ll i=0; i<n; i++)
    {
        cin >> a[i].first >>a[i].second;
    }
    sort(a,a+n);
    for(ll i=0; i<n; i++)
    {
        b[i]=a[i].first;
    }
    ll sum[n+1];
    sum[0]=0;
    for(ll i=0; i<n; i++)
    {
        sum[i+1]=sum[i]+a[i].second; //pre-calculating sum of cost instead of calling sum() again and again
    }
    ll dp[n][n];

    vector<vector<ll> > p;

    for(ll i=0; i<n; i++)     //initialize all values of dp array to zero
    {
        vector<ll> t;
        for(ll j=0; j<n; j++)
        {
            dp[i][j]=0;
            t.push_back(-1);
        }
        p.push_back(t);
    }

    for(ll k=0; k<n; k++)
    {
        ll i=0;
        for(ll j=k; j<n; j++)
        {
            ll min=LONG_LONG_MAX;
            for(ll m=j; m>=i; m--)
            {
                ll temp1=0,temp2=0;
                if(i<m) temp1=dp[i][m-1];
                if(m<j) temp2=dp[m+1][j];

                ll temp=temp1 + temp2 + (sum[j+1]-sum[i]); //taking all possibilities for minimum cost
                if(min>=temp)
                {
                    min=temp;
                    p[i][j]=m;
                }
            }
            dp[i][j]=min;             //dp value set as minimum value
            i++;
        }
    }
    cout<<"Minimum Cost : "<<dp[0][n-1]<<endl<<endl;  //at dp[0][n-1] total minimum cost stored

    cout<<"Optimal BST with minimum cost as under : "<<endl<<endl;

    print(p,0,n-1,b,0);    //print function
    ll i=0;
    while(level[i].size())   //printing level of BST
    {
        cout<< "Level "<<i+1<<": ";
        for (std::vector<ll>::const_iterator j = level[i].begin(); j != level[i].end(); ++j)
        {
            std::cout << *j <<" ";
        }
        cout<<endl;
        i++;
    }
    return 0;
}
