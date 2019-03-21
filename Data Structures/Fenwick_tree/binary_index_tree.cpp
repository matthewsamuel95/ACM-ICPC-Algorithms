#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>   pii;
typedef vector< pii>      vii;
typedef vector<int>     vi;
typedef vector< vi >    vvi;
typedef long long int   LL;
#define pb push_back
#define mp make_pair
#define scan(n) scanf("%d",&n)
#define print(n) printf("%d\n",n)
#define longscan(n) scanf("%lld",&n)
#define longprint(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
/*void sieve(int n)
  {
          for(int i=2;i*i<=100000;i++) for(int j=2*i;j<=100000;j+=i) if(!sie[j]) sie[j]=1;
          }*/
int n;
int bit[10000];
void update(int x, int val)
{
    for(; x <= n; x += x & -x)
    {
        bit[x] += val;
    }
}

int query(int x)
{
    int sum = 0;
    for(; x > 0; x-= x&-x)
    {
        sum+= bit[x];
    }
    return sum;
}
int main()
{
    int q;
    cin >> n >> q;
    int a[n+9], quer[q+9];
    for(int j=1;j<=n;j++)
    {
        cin >> a[j];
        update(j,a[j]);
    }
    for(int j=1;j<=q;j++)
    {
        cin >> quer[j];
    }
    for(int j=1;j<=q;j++)
    {
        cout << query(quer[j]) << "\n";
    }
    return 0;
}
