// Convert an m-ary number to decimal number.
#include<bits/stdc++.h>
using namespace std;

string num="0123456789ABCDEF";
int mToTen(string n, int m) 
{
	int multi=1;
	int result=0;
	for (int i=n.size()-1;i>=0;i--)
	{
		result+=num.find(n[i])*multi;
		multi*=m;
	}
return result;
}

int main()
{
	string str = "FF";
	int m = 16;
	int ans = mToTen(str,m);
	cout<<ans;
}
