# Breadth First Search (BFS)

There are many ways to traverse graphs. BFS is the most commonly used approach.

BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). You must then move towards the next-level neighbour nodes.

As the name BFS suggests, you are required to traverse the graph breadthwise as follows:

* First move horizontally and visit all the nodes of the current layer
* Move to the next layer

## Traversing child nodes

A graph can contain cycles, which may bring you to the same node again while traversing the graph. To avoid processing of same node again, use a boolean array which marks the node after it is processed. While visiting the nodes in the layer of a graph, store them in a manner such that you can traverse the corresponding child nodes in a similar order.

To make this process easy, use a queue to store the node and mark it as 'visited' until all its neighbours (vertices that are directly connected to it) are marked. The queue follows the First In First Out (FIFO) queuing method, and therefore, the neigbors of the node will be visited in the order in which they were inserted in the node i.e. the node that was inserted first will be visited first, and so on.

## Pseudocode
```

BFS (G, s) //Where 'G' is the graph and 's' is the source node.
      let 'Q' be a queue.
      Q.enqueue( s ) //Inserting s in the queue until all its neighbouring vertices are marked.

      mark 's' as visited.
      while ( Q is not empty )
           //Removing that vertex from queue, whose neighbour 'v' will be visited now
           v  =  Q.dequeue( )

          //processing all the neighbours of 'v'  
          for all neighbours 'w' of 'v' in Graph 'G'
               if 'w' is not visited 
                        Q.enqueue( w )             //Stores 'w' in 'Q' to further visit its neighbour
                        mark 'w' as visited.
```
