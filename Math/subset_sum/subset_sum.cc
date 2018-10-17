#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,i,j,k,sum;

bool is_subset_sum(int m,int sum){
	if(sum==0)return true;
	if(m==0 && sum!=0)return false;
	if(v[m-1]>sum)return is_subset_sum(m-1,sum);
	return is_subset_sum(m-1,sum)||is_subset_sum(m-1,sum-v[m-1]);
}

int main(){
	n=6;
	v.push_back(3);
	v.push_back(34);
	v.push_back(4);
	v.push_back(12);
	v.push_back(5);
	v.push_back(2);
	sum=9;
	if(is_subset_sum(n,sum)){
		cout<<"found\n";
	}else{
		cout<<"not found\n";
	}
	return 0;
}