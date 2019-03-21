#include <iostream>
using namespace std;

//Longest Increasing Decreasing Subsequence
int lidss(int n,int arr[])
{
    if(n==0)
        return 0;
    int lenI[n];
    int lenD[n];

    for(int i=0; i<n; i++)
    {
        lenI[i]=1;
        lenD[i]=1;
    }

    //calculating increasing subsequence
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[j]<arr[i]  &&  lenI[i]<lenI[j]+1)
            {
                lenI[i]=lenI[j]+1;
            }
        }
    }

    //calculating decreasing subsequence
    for(int i=n-2; i>=0; i--)
    {
        for(int j=n-1; j>i; j--)
        {
            if(arr[j]<arr[i]  &&  lenD[i]<lenD[j]+1)
            {
                lenD[i]=lenD[j]+1;
            }
        }
    }

    //calculate longest Increasing and then decreasing subsequence starting from each element
    int max=1;
    for(int i=0; i<n; i++)
    {
        int len=lenI[i]+lenD[i]-1;
        if(max<len)
        {
            max=len;
        }
    }
    return max;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<lidss(n,arr)<<endl;
    }
    return 0;
}



