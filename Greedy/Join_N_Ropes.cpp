#include<bits/stdc++.h>
using namespace std;

int join_ropes(int a[],int n){
	int total=0;
	vector<int> v;
	for(int i=0;i<n;i++){
		v.push_back(a[i]);
	}
	while(v.size()>1){
		sort(v.begin(),v.end());
		total+=v[0]+v[1];
		v.push_back(v[0]+v[1]);
		v.erase(v.begin(),v.begin()+2);
	}
	
	return total;
}

int main()
{
	int a[]={4,2,5,6},n=sizeof(a)/sizeof(a[0]);
	cout<<join_ropes(a,n);
	
	return 0;
}
