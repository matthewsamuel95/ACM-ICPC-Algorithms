#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

void printOrder(char &name,int *path,int i, int j, int n)           //Printing sequance using recursion
{
    if (i == j)
    {
        cout << name;
        name++;
        return;
    }

    cout << "(";

    printOrder(name,path,i,*((path+i*n)+j),n);

    printOrder(name,path,*((path+i*n)+j)+1,j,n);

    cout << ")";
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int dp[n][n];
    int path[n][n];

    for (int i=1; i<n; i++)
        dp[i][i]=0;

    for (int L=2; L<n; L++)
    {
        for (int i=1; i<n-L+1; i++)
        {
            int j=i+L-1;
            dp[i][j]=INT_MAX;
            for (int k=i; k<=j-1; k++)
            {
                int temp = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if (temp < dp[i][j])
                {
                    dp[i][j] = temp;                                            //Adding minimum numbers of operations for ith to jth matrix multiplication
                    path[i][j] = k;                                             //For printing path
                }
            }
        }
    }

    char name = 'A';

    cout << "Minimuum numbers of operations are " << dp[1][n-1]<<endl;
    cout << "Bracketing for minimum operations is";
    printOrder(name,(int *)path,1,n-1,n);

    return 0;
}
