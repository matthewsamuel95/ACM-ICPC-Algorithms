/*
All submissions for this problem are available.Prime numbers are arranged in a ordered list U, in increasing order. Let S be a sublist of U with a unique property that for every element A belonging to list S, if i denotes the index of A in list U, than i also belongs to list U.

Given N, find sum of first N elements of list S, assuming 1-based indexing.

As the sum can be very large, print the sum modulo 109+7.

Input:
-The first line of the input contains a single integer T denoting the number of test cases.

-Only line of each test case has an integer N .

Output:
For each test case, print a single integer denoting the sum of first N elements of set S modulo 109+7.

Constraints
1=T=10000
1=N=1000*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int v[100000]={0};
int su[100000]={0};
int prime[100000];
void calculate()
{
    int i,j;
       int sum;
    v[0]=1;
    	v[1]=1;
    	su[0]=0;
		for(i=2;i<sqrt(100000);i++)
   if(v[i]==false)
     for (j = pow(i,2);j<=100000;j+=i)
       v[j] = true;
       sum=0;
       int k=0;
       prime[0] = 0;
       for(i=1;i<=100000;i++)
       {
       	//king=0;
           if(v[i]==0)
           {
		   k++;
           	prime[k] = i;
           	//cout<<i;
		   }
           //v[]
       }
       int lo;
       su[0] = 0;
       lo=1;
       for(i=1;i<=k;i++)
       {
       	if(v[i]==0)
       	{
       		sum = sum+prime[i];
       		su[lo] = sum;
       		lo++;
		   }
	   }
}
int main()
{
std::ios::sync_with_stdio(false);
//cin.tie(0);
	
	int t;
	long int n;
	calculate();
    cin>>t;
   
   // vector<int> v;
 
    while(t--)
    {
    	cin>>n;
    //	cout<<prime[n];
    	
       cout<<su[n]<<endl;
       //v.clear();
	}
	return 0;
}
