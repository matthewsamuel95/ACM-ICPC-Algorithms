#include<iostream>
using namespace std;
 
# define V 5

void printSolution(int color[]);

bool isSafe (int v, int graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && c == color[i])
            return false;
    }        
    return true;
}
 

bool graphColoringUtil(int graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;
 
   
    for (int c = 1; c <= m; c++)
    {
       
        if (isSafe(v, graph, color, c))
        {
           color[v] = c;
          if (graphColoringUtil (graph, m, color, v+1) == true)
             return true;
 
           color[v] = 0;
        }
    }
 
    return false;
}
 
bool graphColoring(int graph[V][V], int m)
{
    int *color = new int[V];
    for (int i = 0; i < V; i++)
       color[i] = 0;
 
   if (graphColoringUtil(graph, m, color, 0) == false)
    {
      cout<<"Solution does not exist";
      return false;
    }
 
    printSolution(color);
    return true;
}
 
void printSolution(int color[])
{
    cout<<"Solution Exists:"<<" Following are the assigned colors"<<endl;
             
    for (int i = 0; i < V; i++)
      cout<<" "<<color[i];
    
    cout<<endl;
}
 
int main()
{
	int graph[V][V];
	cout<<"enter adjacency matrix in row major order:"<<endl;
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cin>>graph[i][j];
		}
	}
	
	int m;
	cout<<"enter the number of colors";
	cin>>m;
	
    graphColoring (graph, m);
    return 0;
}
