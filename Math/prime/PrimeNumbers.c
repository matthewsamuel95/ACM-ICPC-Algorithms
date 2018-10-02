#include<stdio.h>
int lp[1000000];
int main()
{
	// Question : Calculate number of prime factors of all numbers from 1 to nos 
	// nos >=1 && nos<=100000
	// For example if nos = 5 , Ans = (1-> 0) + (2->1) + (3->1) + (4->2) + (5->1) = 5
	// Time Complexity = (O(nlogn))
	int nos;
	scanf("%d",&nos);
	for(int i=2;i<=nos;i++)
	{
		// lp array stores the lowest prime factor that divides nos
		// for example lp[4]=2 lp[49]=7
		if(lp[i]==0)
		{
			lp[i]=i;
			for(int j=2*i;j<=nos;j+=i)
			{
				if(lp[j]==0)
					lp[j]=i;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=nos;i++)
	{
		int temp=i;
		while(lp[temp]!=0)
		{
			temp/=lp[temp];
			ans++;
		}
	}
	printf("%d\n",ans);
}
