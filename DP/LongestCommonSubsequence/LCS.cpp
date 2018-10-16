
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string a,string b){
	int l1=a.size();
	int l2=b.size();
	//2d array for bottom-up dp
	int dp[l1+1][l2+1];

	for(int i=0;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			if(!i || !j)
				dp[i][j]=0;
			else if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{	
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[l1][l2];
}
int main() {
	string a,b;
	cin>>a>>b;
	cout<<lcs(a,b)<<endl;
	return 0;
}