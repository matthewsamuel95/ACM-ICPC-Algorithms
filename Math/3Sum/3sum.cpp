/*Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. 
If there is such a triplet present in array, then print the triplet and return true. 
Else return false. 

For example, if the given array is {12, 3, 4, 1, 6, 9} and given sum is 24, 
then there is a triplet (12, 3 and 9) present in array whose sum is 24.
*/
#include <bits/stdc++.h>

using namespace std;

bool isTripletPresent(int *a,int n,int sum)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==j)
                continue;
            for(int k = 0; k < n; k++)
            {
                if(j==k || k==i)
                    continue;
                if(sum==a[i] + a[j] + a[k])
                    return true;
            }
        }
    }
    return false;
}

int main() 
{
    int n,sum;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> sum;
    if(isTripletPresent(a,n,sum))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}