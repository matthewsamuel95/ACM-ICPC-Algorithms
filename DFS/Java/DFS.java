
import java.io.*;
import java.util.*;

// Main class
class DFS{

    // Define the Adjacency Lists
    // It is an array of LinkedList
    private LinkedList<Integer>[] adjacencyLists;

    // No. of vertices
    private int nodes;   

    DFS(){
        // constructor
        
        // first we will define how many nodes we will store
        // for this example lets store 12 nodes
        this.nodes = 12;
        
        // define the linkedlist
        adjacencyLists = new LinkedList[nodes];
        
        // make each element in this array a linkedlist as well
        for (int i=0; i<nodes; i++)
            adjacencyLists[i] = new LinkedList();
        
    }

    // method to add edge in the graph
    void addEdge(int source, int destination){
        // On the adjacencyLists at the index source we will get a linked list
        // add destination to that linked list 
        adjacencyLists[source].add(destination);
    }

    void DFS(int n, boolean visited[]){
        //mark it visited 
        visited[n]=true;

        System.out.print(n + "   ");
        
        // Traverse the graph until the queue is empty
        Iterator<Integer> itr = adjacencyLists[n].listIterator();

        while(itr.hasNext()){
            int adjNode = itr.next();
            // check if this node is already visited
            if(visited[adjNode]==false){    
                // Make this node visited and add it to queue  
                DFS(adjNode, visited);
            }
        }
    }

    // method for BFS travarsal
    void DFSTravarsal(int source){
        // Graphs contain cycle and hence we need to maintain a record for visited nodes
        // in each traversal we need to keep track of all the visited nodes and if we visit that node again, DANGER! It is cycle
        // To do this we will maintain a boolean array which represents each node by index
        // by default this array will be false
        boolean visited[] = new boolean[this.nodes];

        DFS(source, visited);
        
        
    }

    public static void main(String[] args){
        // This method adds nodes to the graph and 
        // Calls the BFS Travarsal method on it

        DFS dfs = new DFS();
        dfs.addEdge(0, 1);
        dfs.addEdge(0, 2);
        dfs.addEdge(0, 3);
        dfs.addEdge(1, 4);
        dfs.addEdge(1, 5);
        dfs.addEdge(3, 6);
        dfs.addEdge(3, 7);
        dfs.addEdge(4, 8);
        dfs.addEdge(4, 9);
        dfs.addEdge(6, 10);
        dfs.addEdge(6, 11);

        System.out.println("BFS Traversal is:");

        dfs.DFSTravarsal(0);

        System.out.println();
    }
}