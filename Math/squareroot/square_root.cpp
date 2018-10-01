#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter Number\n";
	cin>>n;
	double start =0, end = (double)n;
	while(end-start > 0.00001)
	{
		double mid = (start+end)/2.0;
		if(mid*mid > n)
		end = mid;
		else if(mid*mid<n)
		start = mid;
		else
		{
			start = mid;
			break;
		} 
	}
	cout<<"The square root of the number is: "<<start<<endl;
	return 0;
}
