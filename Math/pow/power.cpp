#include<bits/stdc++.h>
using namespace std;
long long power(long long base, long long pow)
{
	long long i;
	long long res=1;
	for(i=1;i<=pow;i++)
	{
		res=res*base;
	}
	return res;
}
int main()
{
	long long base,pow;
	cin>>base>>pow;
	cout<<power(base,pow);
}
