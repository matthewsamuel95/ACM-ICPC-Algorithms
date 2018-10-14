import java.io.*;
import java.util.*;

class PDK{

    private LinkedList<Integer>[] adjacencyLists;

    private int nodes;   

    PDK(){
       
        this.nodes = 12;
        
        adjacencyLists = new LinkedList[nodes];
        
        for (int i=0; i<nodes; i++)
            adjacencyLists[i] = new LinkedList();
        
    }

    void addEdge(int source, int destination){
       
        adjacencyLists[source].add(destination);
    }

    void PDK(int n, boolean visited[]){
        visited[n]=true;

        System.out.print(n + "   ");
       
        Iterator<Integer> itr = adjacencyLists[n].listIterator();

        while(itr.hasNext()){
            int adjNode = itr.next();
           
            if(visited[adjNode]==false){    
                  
                PDK(adjNode, visited);
            }
        }
    }
