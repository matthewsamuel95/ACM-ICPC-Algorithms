//Prints the Lexicographically smallest TS order.
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector< vector<int> > v(100);
vector<bool> visit(100,false);
stack<int> st;
void toposort(int s)
{
	visit[s]=true;
	for(int i=0;i<v[s].size();i++)
	{
		if(visit[v[s][i]]==false)
		{
			toposort(v[s][i]);
		}
	}
	st.push(s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    while(m--)
    {
    	int x,y;
    	cin>>x>>y;
    	v[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    sort(v[i].rbegin(),v[i].rend());
    for(int i=n;i>=1;i--)
    if(visit[i]==false)
    toposort(i);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
