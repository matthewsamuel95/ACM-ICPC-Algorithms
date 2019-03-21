#include<bits/stdc++.h>
using namespace std;
//Normal Brute force take O(N) time which is not good so we use this
 
// Fast Powerusing divide and conquer O(logN) time and O(logN) space
//space = MAx operation of call stack(O(logB) * extra space constr. m each call O(log1);
int fast_power(int a,int b)
{
	if(b==0)
		return 1;
	int smallerValue=fast_power(a,b/2);
	smallerValue *=smallerValue;
	if(b%2==1)
		return a*smallerValue;
	return smallerValue;
}
// Fast Power using BitMasking O(logN) time and O(1) space
int fast_power_BitMask(int a,int b)
{
	int res=1;
	while(b>0)
	{
		int last_bit=(b&1);
		if(last_bit)
			res=res*a;
		a=a*a;
		b=b>>1;//right shift to remove the rightmost bit
	}
	return res;
	
}
int main()
{
	cout<<fast_power(3,5)<<endl;
	return 0;
}
