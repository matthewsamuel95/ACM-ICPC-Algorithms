
/*
Program to print all possible increasing subsequences of an array of length K

@Author : sanithps_98
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v;
vector<vector<ll> > result;

void subset(ll arr[],ll k,ll n,ll idx)
{
if(idx==n)
return;

if(k==1)
{
for(ll i=idx;i<n;i++)
{
v.push_back(arr[i]);
result.push_back(v);
v.pop_back();
}
}

for(ll j=idx;j<n;j++)
{
v.push_back(arr[j]);
subset(arr,k-1,n,j+1);
v.pop_back();
}
}

int main()
{
ll n,k;  // n - length of the input array
cin>>n>>k; // k - length of the required subsequence
ll arr[n];

for(ll i=0;i<n;i++)
cin>>arr[i];

sort(arr,arr+n);

subset(arr,k,n,0);

for(ll i = 0;i<result.size();i++)
{
for(ll j = 0;j<result[i].size();j++)
{
cout << result[i][j] << " ";
}
cout << endl;
}
}
