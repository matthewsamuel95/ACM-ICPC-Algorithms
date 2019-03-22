//Converting decimal number to m-ary number.
#include<bits/stdc++.h>
using namespace std;

char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string tenToM(int n, int m)
{
	int temp=n;
	string result="";
	while (temp!=0)
	{
		result=a[temp%m]+result;
		temp/=m;
	}
return result;
}

int main()
{
	int n = 15;
	int m = 8;
	string str = tenToM(n,m);
	cout<<str;
}
