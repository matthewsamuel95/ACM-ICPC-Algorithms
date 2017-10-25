#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define maxn 1000009
bool sum[maxn];

bool subsetSum(vector<int> &a, int SUM){
	sum[0]=1;
	int n = a.size();
	for(int i=0;i<n;i++){
		for(int j=a[i];j<=SUM;j++){
			if(sum[j-a[i]])sum[j]=1;
		}
	}
	return sum[SUM];
}


int main(){

	fill(sum,sum+maxn,0);
	vector<int> a;
	a.pb(3);a.pb(34);a.pb(4);a.pb(12);a.pb(5);a.pb(2);
	int SUM = 9;
	sort(a.begin(), a.end());
	bool ans = subsetSum(a,SUM);
	cout<<ans<<endl;

}
