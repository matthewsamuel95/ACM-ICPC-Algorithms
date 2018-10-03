#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    string a, b;
    lli n, i, x=0;
    cin>>n>>a>>b;
    for(i=0;i<n-1;i++){
        if(a[i]!=b[i]){
            if(a[i+1]!=b[i+1] && a[i]!=a[i+1]){
                a[i]=b[i];
                a[i+1]=b[i+1];
                x++;
                i++;
            }
            else{
                a[i]=b[i];
                x++;
            }
        }
    }
    if(a[n-1]!=b[n-1]){
        x++;
    }
    cout<<x<<endl;
}
