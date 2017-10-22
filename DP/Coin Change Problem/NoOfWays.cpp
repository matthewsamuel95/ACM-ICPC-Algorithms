#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

Algorithm : Coin Change Problem (No of Ways)
Type : DP

Problem 

You have m types of coins available in infinite quantities where the value of each coin is given in the array C = [c0, c1....c m-1] . Can you determine the number of ways of making change for n units using the given types of coins? The order of coins doesn’t matter.

Example

Input

4 3
1 2 3

Output 

4

Explanation

There are 4 ways to make n=4 with C=1,2,3

{1,1,1,1}
{1,1,2}
{2,2}
{1,3}

*/

long mem[51][251];

long coins(vector <int> S, int m, int n){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(n >= 1 && m <= 0) return 0;
    if(mem[m][n] != -1) return mem[m][n];
    
    return mem[m][n] = coins(S,m-1,n) + coins(S,m,n-S[m-1]);
}

int main() {
    int N,M;
    cin >> N >> M;
    vector <int> S(M);
    for(int i = 0; i < 51; i++) for(int j = 0;j < 251; j++) mem[i][j]=-1;
    for (int i = 0; i < M; i++) cin >> S[i];
    cout << coins(S,M,N) << endl;
    
    return 0;
}
