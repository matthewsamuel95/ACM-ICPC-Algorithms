#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define maxn 1000009
/*
Subset sum problem
Both of x + (x + 1) and x + (x + 2) might be the key to the answer, 
that's why each sum matrix need 2 elements(one for odd and another for
even), and if the value of sum n has showed up, then change n rows value
to 1. Notice that in this case we assume all of a's element will be
positive
*/
bool sum[2][maxn];

// Explanation
bool subsetSum(vector<int> &a, int SUM){
	// Init sum start from 0
	sum[0][0]=1;
	sum[1][0]=1;
	int n = a.size();
	// n for how many elements in the vector a
	for(int i=0;i<n;i++){		 
		// Check if the value of guess(where a[i] <= guess <= SUM) - 
		// current element of vector a is exist, then we can change our
		// guessing value's element to 1(sum[1][j] = 1 or sum[0][j] =
		// 1), so on until our guessing value equals to target or reach
		// the end of the vector
		for(int j=a[i];j<=SUM;j++){
			if(i%2){
				if(sum[0][j-a[i]])sum[1][j]=1;
			}else{
				if(sum[1][j-a[i]])sum[0][j]=1;
			}
		}
		// After checking then change sum[0][value] = 1 and
		// sum[1][value] = 1 if sum[0][value] = 1 or sum[1][value] = 1 
		for(int j=a[i];j<=SUM;j++){
			if(i%2){
				sum[0][j]=sum[0][j]||sum[1][j];
			}else{
				sum[1][j]=sum[1][j]||sum[0][j];
			}
		}
	}
	// If both two elements of SUM row equals to 1, that means we have
	// achieve the target
	return sum[0][SUM]||sum[1][SUM];
}


int main(){
	// Init all of sum matrix's elements to 0
	memset(sum,0,sizeof(sum));
	// Create vector a to store the set
	vector<int> a;
	a.pb(3);a.pb(34);a.pb(4);a.pb(12);a.pb(5);a.pb(2);	
	int SUM = 9;
	// Verify our Subset sum is true or false
	bool ans = subsetSum(a,SUM);
	if(ans) cout<<"subset with the given sum exists"<<endl;
	else cout<<"no required subset present";
}
