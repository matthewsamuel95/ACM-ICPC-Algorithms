#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long val=0;
    long long arr[MAX+1]={0};
    for(long long i=2; i<=MAX; i++){
        if(!arr[i]){
            val+=i;
        }
        for(long long j=i; j<=MAX; j+=i){
            arr[j]=val;
        }
    }
    long long t,temp;
    cin>>t;
    while(t--){
        cin>>temp;
        cout<<arr[temp]<<"\n";
    }
    return 0;
}

