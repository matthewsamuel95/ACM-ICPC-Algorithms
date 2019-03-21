#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    lli n;
    cin >> n;
    lli a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    lli ans = 1;
    lli out = 1;
    for(int i = 1; i<n; i++)
    {
        if(a[i] > a[i-1])
        {
            ans++;
        }
        else
        {
            ans = 1;
        }
        out = max(out,ans);
    }
    cout << out << endl;
}
