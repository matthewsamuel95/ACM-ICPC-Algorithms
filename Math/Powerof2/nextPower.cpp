//Write a function that, 
//for a given no n, finds a number p which is greater than or equal to n and is a smallest power of 2.
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
    cin >> n;
    int p;
    for(p = n; p < INT_MAX; p++)
    {
        float sq = log2(p);
        int sqi = (int) sq;
        if(sq-sqi== 0)
            break;
    }
    cout << p << "\n";
}
