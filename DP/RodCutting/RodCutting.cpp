#include<iostream>
#include<cstdio>
#include<climits>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long int
#define vec vector<int>

using namespace std;

int ar[15]={0},price[15]={0,1,5,8,9,10,17,17,20,24,30};

int dp(int size)
{
	if(size==1) return price[1];
	int Max=price[size];
	
	for(int i=1;i<=size/2;++i)
	{
		if(ar[i]==0)
			ar[i]=dp(i);
		if(ar[size-i]==0)
			ar[size-i]=dp(size-i);
		Max=max(Max,ar[i]+ar[size-i]);
	}
	ar[size]=Max;
	return Max;
}

int main()
{
	ar[1]=price[1];
	cout<<dp(8)<<endl;
	cout<<dp(4)<<endl;
	
	return 0;
}
