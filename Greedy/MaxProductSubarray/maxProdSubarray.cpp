#include<bits/stdc++.h>
using namespace std;

int maxProd(int arr[],int n)
{
    int f=1,r=1;
    int mxans = arr[0];
    for(int i=0;i<n;i++){
        f*=arr[i];
        r*=arr[n-i-1];
        mxans = max(mxans,max(f,r));
        if(f==0) f=1;
        if(r==0) r=1;
    }
    return mxans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<maxProd(arr,n);
    return 0;
}
