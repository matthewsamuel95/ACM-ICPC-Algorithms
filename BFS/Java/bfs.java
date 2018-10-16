
import java.io.*;
import java.util.*;

// Main class
class BFS{

    // Define the Adjacency Lists
    // It is an array of LinkedList
    private LinkedList<Integer>[] adjacencyLists;

    // No. of vertices
    private int nodes;   

    BFS(){
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

    // method for BFS travarsal
    void BFSTravarsal(int source){
        // Graphs contain cycle and hence we need to maintain a record for visited nodes
        // in each traversal we need to keep track of all the visited nodes and if we visit that node again, DANGER! It is cycle
        // To do this we will maintain a boolean array which represents each node by index
        // by default this array will be false
        boolean visited[] = new boolean[this.nodes];

        // Barbecue starts with a 'B' and ends with a sound like 'q' hence BFS -> Queue
        // A data structure that when queried gives you the oldest element, based on the order they were inserted. 
        // A queue is what you need in this case since it is first-in-first-out(FIFO).
        LinkedList<Integer> queue = new LinkedList<Integer>();

        // We will start with Source node given as the input.
        // So mark it visited 
        visited[source]=true;

        // Add this node to Queue
        queue.add(source);

        // Traverse the graph until the queue is empty
        while(queue.size()!= 0){

            // Dequeue a node from the queue using poll method 
            // Java’s Linked list class offers a function that allows a "Queue Based" working called poll().
            int node = queue.poll();

            // Display this node
            System.out.print(node + "   ");

            // Now we know at index = node  in  the adjacencyLists we have a linked list which contains all the connections which are possible from this node
            // Lets iterate over that linked list
            // We will use Iterator 
            Iterator<Integer> itr = adjacencyLists[node].listIterator();

            // these are all the adjacent nodes
            // Loop over each node 
            while(itr.hasNext()){
                 int adjNode = itr.next();

                 // check if this node is already visited
                 if(visited[adjNode]==false){
                     
                    // Make this node visited and add it to queue  
                    visited[adjNode] = true;
                    queue.add(adjNode);
                 }
            }    
        }
    }

    public static void main(String[] args){
        // This method adds nodes to the graph and 
        // Calls the BFS Travarsal method on it

        BFS bfs = new BFS();
        bfs.addEdge(0, 1);
        bfs.addEdge(0, 2);
        bfs.addEdge(0, 3);
        bfs.addEdge(1, 4);
        bfs.addEdge(1, 5);
        bfs.addEdge(3, 6);
        bfs.addEdge(3, 7);
        bfs.addEdge(4, 8);
        bfs.addEdge(4, 9);
        bfs.addEdge(6, 10);
        bfs.addEdge(6, 11);

        System.out.println("BFS Traversal is:");

        bfs.BFSTravarsal(0);

        System.out.println();
    }
}