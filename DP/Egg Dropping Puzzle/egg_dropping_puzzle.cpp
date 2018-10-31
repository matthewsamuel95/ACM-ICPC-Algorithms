
#include <iostream>

#define MAX_EGGS 100
#define MAX_FLOORS 100
#define INF 1000000000

using namespace std;

int memo[MAX_EGGS][MAX_FLOORS];

/*
 *  Returns the minimum number of attempts
 *  needed in the worst case for n eggs
 *  and k floors.
 *  Time complexity: O(n*k^2)
 */
int eggDrop(int n, int k) {
    
    if(k == 0) return 0; 
    if(k == 1) return 1; 
    if(n == 1) return k; 


    if(memo[n][k] > -1) return memo[n][k]; 

    int ans = INF;
    for(int h = 1; h <= k; ++h) {
        
        ans = min(ans, max(    
            eggDrop(n-1, h-1), 
            eggDrop(n, k-h)    
        ));
    }

    return memo[n][k] = ans + 1; 
}

int main() {
    
    memset(memo, -1, sizeof memo);

    cout << eggDrop(2, 100) << '\n';
    cout << eggDrop(10, 5) << '\n';
    cout << eggDrop(10, 100) << '\n';
    return 0;
}

