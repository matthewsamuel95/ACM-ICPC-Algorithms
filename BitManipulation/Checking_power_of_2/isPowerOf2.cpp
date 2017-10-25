#include<iostream>

using namespace std;

bool isPowerOf2(int no)
{
	if(no && (no & (no-1))==0)       // lets the no is x.If x is power of 2,then x & (x-1) must be equal to zero
	return true;
	else                             // If x isn't power of 2,then x & (x-1) will be greater than or equal to x
	return false;
}

int main()
{
	int no; cin>>no;
	
	if(isPowerOf2(no))
	cout<<"Yes\n";
	else
	cout<<"No\n";
	
	return 0;
}
