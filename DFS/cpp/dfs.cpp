
/*
    This code is the self work of Rohit Rao.
    It is intended to be used only for educational purposes.
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > v(100,vector<int>());
bool visited[100];

//  This is the main DFS function which does the Depth First Search
// from a vertex that not been visited till now.
// This approach is basically used when there are more than one connected components.
// However, if there is only one connected component, then there will be only a single call to the DFS function.
// For a graph having n connected components there will be n call to the DFS function.
void dfs(int node)
{
    // mark the node as visited, so that we do not visit it again.
    visited[node] = true;

    // For all nodes adjacent to the given node and have not yet been visited, we apply DFS function again.
    for(int i=0;i<v[node].size();i++)
    {
        int u = v[node][i];
        if(!visited[u])
        {
            cout<<u<<"  ";
            dfs(u);
        }
    }
}

int main()
{
    // num_vertices is the no of vertices/node in the given graph.
    // edges is the no of total edges in the given graph.
    int num_vertices=0,x,y,i,j,edges=0;
    cin>>num_vertices>>edges;

    // Creating the bi-directed graph.
    for(i=1;i<=edges;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(visited,false,sizeof(visited));

    for(i=1;i<=num_vertices;i++)
    {
        if(!visited[i])
        {
            cout<<"Calling the dfs function with "<<i<<endl<<"List of all discoverable vertices from it are "<<endl;
            dfs(i);
        }
    }
    return 0;
}
