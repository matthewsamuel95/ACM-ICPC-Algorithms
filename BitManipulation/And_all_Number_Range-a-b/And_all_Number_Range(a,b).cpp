//We find the And of all numbers in range a to b inclusive in O(1) Solution
/*
1.XOR a and b.
2.Find its next power of 2.
3.Subtract 1.
4.Flip its bits and AND with either a or b.
5. a & ~(nextpowerof2(a^b)-1)
*/

#include<bits/stdc++.h>
using namespace std;

int And_Range(int a,int b){
	int xo=a^b;
	//int power = pow(2, ceil(log(xo)/log(2))); Slow MEthod
	/*int power = 1;
	while (xo >>= 1) power <<= 1;
	*/ // lowest power
	int power = 2;
	xo--;    // <<-- UPDATED
	while (xo >>= 1) power <<= 1;
	
	//cout<<power;
	power=power-1;
	int nextbit=~(power);
	int ans = a&nextbit;
	return ans;
	
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<And_Range(a,b);
	
	return 0;
	
}
