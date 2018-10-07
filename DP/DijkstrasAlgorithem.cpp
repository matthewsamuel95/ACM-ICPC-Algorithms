#include<limits.h>
#include<stdio.h>
#define max 50

//global variables
int graph[max][max];
bool isvisited[max];
int dist[max];

int minDistance(int n,int src){
    int min = INT_MAX , min_vertex;
    for(int v=0;v<n;v++){
        if(!isvisited[v] && dist[v] <= min)
            min=dist[v],min_vertex = v;        
    }
    return min_vertex;
}

void display(int src,int n){
    printf("\nVertex \t Distances from source %d\n",src);
    for(int i=0;i<n;i++){
        printf("%d \t\t %d\n",i,dist[i]);
    }
}

void dijkstra(int src,int n){
    //set all distances to infinity and isvisited to false
    for(int i = 0;i<n;i++)
        dist[i] =INT_MAX,isvisited[i]=false;
    
    //self loops distance is zero
    dist[src] = 0;

    //to find shortest path from src to all vertices
    for(int i=0;i<n-1;i++){
        int minV =minDistance(n,src);
        isvisited[minV] =true;
        printf("%d",minV);
        for(int v=0;v<n;v++){
            if(!isvisited[v] && graph[minV][v] && dist[minV] != INT_MIN && dist[minV] + graph[minV][v] < dist[v])
                dist[v] = dist[minV] + graph[minV][v];
        }
    }
    display(src,n);
}

int main(){
    int sizeOfGraph,Edges,src;
    printf("Enetr no of vertices:");
    scanf("%d",&sizeOfGraph);
    for(int i = 0;i<sizeOfGraph;i++)
        for(int j=0;j<sizeOfGraph;j++){
            graph[i][j] = 0;
        }
    printf("Enter the no of edges:");
    scanf("%d",&Edges);
    char ch = 'A';
    int j,k;
    for(int i= 0;i<Edges;i++){
        printf("Enter the end vertices of edge %c : ",ch++);
        scanf("%d %d",&j,&k);
        printf("Enter the distance of %d - %d : ",j,k);
        scanf("%d",&graph[j][k]);
        graph[k][j] = graph[j][k];
    }    
    printf("Enter the source:");
    scanf("%d",&src);    
    dijkstra(src,sizeOfGraph);    
    return 0;    
}
