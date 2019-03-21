#include<bits/stdc++.h>
using namespace std;
const long int p=1000000007;
int f[505][250005]={},g[505][250005]={};
long int perwithinv(int n,int k)
{	
	long int sum=0;
	cout << n << " " << k << "\n";
	if(k!=0&&n!=0)
	{
		for(int i=k;k>=0;k--)
		{
			sum=sum+perwithinv(n-1,i);
			f[n][k]=sum;
			cout << sum << "=sum\n";
			return sum;
		}
	}
	else
	{
		if(n==0)
		{
			return 0;
		}
		if(k==0)
		{
			cout << "----\n";
			return 1;
		}
	}
	
}

int make_g(int x, int y)
{
	if(y==0)
	{
		g[x][0]=perwithinv(x,0);
		return f[x][0];
	}
	else
	{
		cout << make_g(x,y-1)<< "======++\n";
		g[x][y]=make_g(x,y-1)+perwithinv(x,y);
		cout << g[x][y] << "=g[][]\n";
		return g[x][y];
	}
	
}

long int fact(int n)
{
	long int facto=1;
	if(n==1||n==0)
		return 1;
	else
		facto=(facto*fact(n-1))%p;
	return facto;
}

int main()
{
	int t,k;
	cin >> t >> k;
	int i;
	long int sum1=0;
	for(i=1;i<=t;i++)
	{
		sum1=(sum1+(make_g(i,k)*fact(t)*(t-i+1))%p)%p;
	}
	cout << sum1;
			
}
