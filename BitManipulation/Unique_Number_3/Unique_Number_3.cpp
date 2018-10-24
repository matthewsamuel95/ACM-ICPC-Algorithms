//Find Unique number in array all elements occur 3times but unique elemnt occur only 1 time

#include<bits/stdc++.h>
using namespace std;
int UniqueNumber3(int *a,int n){
	int cnt[64]={0};
	int no=0;
	for(int i=0;i<n;i++){
		no=a[i];
		int j=0;
		while(no>0){
			cnt[j]+=(no&1);
			j++;
			no=no>>1;
		}
	}
	int p=1;
	int ans=0;
	for(int i=0;i<64;i++){
		//cout<<cnt[i]<<" ";
		cnt[i]%=3;
		
		ans+=cnt[i]*p;
		p=p<<1;//p=p*2
	}
	return ans;
}
int main()
{
	int a[]={7,7,3,4,2,3,3,4,4,7};
	int n=sizeof(a)/sizeof(int);
	cout<<UniqueNumber3(a,n)<<endl;
	
	return 0;
	
	
}
