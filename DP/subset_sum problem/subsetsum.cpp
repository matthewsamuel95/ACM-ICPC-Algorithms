#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define maxn 1000009
bool sum[2][maxn];

bool subsetSum(vector<int> &a, int SUM){
	sum[0][0]=1;
	sum[1][0]=1;
	int n = a.size();
	for(int i=0;i<n;i++){		 
		for(int j=a[i];j<=SUM;j++){
			if(i%2){
				if(sum[0][j-a[i]])sum[1][j]=1;
			}else{
				if(sum[1][j-a[i]])sum[0][j]=1;
			}
		}		 		
		for(int j=a[i];j<=SUM;j++){
			if(i%2){
				sum[0][j]=sum[0][j]||sum[1][j];
			}else{
				sum[1][j]=sum[1][j]||sum[0][j];
			}
		}
	}
	return sum[0][SUM]||sum[1][SUM];
}


int main(){
	memset(sum,0,sizeof(sum));
	vector<int> a;
	a.pb(3);a.pb(34);a.pb(4);a.pb(12);a.pb(5);a.pb(2);	
	int SUM = 9;	
	bool ans = subsetSum(a,SUM);	
	cout<<ans<<endl;
}
