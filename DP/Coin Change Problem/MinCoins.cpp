#include<bits/stdc++.h>
using namespace std;

/*

Algorithm : Coin Change Problem (Minimum Coins)
Type : DP

Problem 

Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?

Example

Input

4 4
1 2 3 5

Output 

2

Explanation

We can make 4 using {2,2} or {1,3}

*/
 
// m is size of coins array (number of different coins)
int minCoins(vector<int> coins, int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];
 
    // Base case (If given value V is 0)
    table[0] = 0;
 
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
 
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[V];
}
 

int main()
{
    int m,V;
    cin >> m >> V;
    vector <int> coins(m);
    for (int i = 0; i < m; i++) cin >> coins[i];
    cout << minCoins(coins, m, V);
    return 0;
}