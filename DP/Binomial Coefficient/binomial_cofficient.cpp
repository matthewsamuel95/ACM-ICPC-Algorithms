#include<iostream>
using namespace std;

/** 
 * We are going to calculate C(n,r) 
 * mathematically proven formula is C(n,r) = C(n-1,r-1) + C(n-1,r)
**/

int min(int a,int b){
    return (a > b) ? b : a;
}

int binomialCoefficient(int n, int r) {
    int DP[n+1][r+1];
    int i,j;

    for(i = 0; i <= n; i++){
        for(j = 0; j <= min(i,r); j++){
            // base case
            if(j == 0 || j == i){
                DP[i][j] = 1;
            } else {
                DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
            }
        }
    }

    return DP[n][r];
}

int main(){
    int n,r;
    cin>>n>>r;

    cout<<"required binomial coefficient is: "<<binomialCoefficient(n,r)<<endl;

    return 0;
}