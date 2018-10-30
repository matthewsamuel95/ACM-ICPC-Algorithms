
from collections import defaultdict
 
#Class to represent a graph
class Graph:
    def __init__(self,vertices):
        self.graph = defaultdict(list) #dictionary containing adjacency List
        self.V = vertices #No. of vertices
 
    # function to add an edge to graph
    def addEdge(self,u,v):
        self.graph[u].append(v)
 
    def topological_sort(self):
        
        #initialise in_degrees
	in_degree = [0 for i in range(self.V)]
        
        #calculate in_degrees of all vertices
	for i in self.graph:
	    for j in self.graph[i]:
		in_degree[j]+=1
        
        #queue to keep track of vertices with 0 in_degree. These will be first in our topological ordering
        queue = []
        for i in range(self.V):
            if(in_degree[i] == 0):
		    queue.append(i)
  

        #list for our topological ordering
        top_order = []       

        # keep track of visited vertices to ensure there is no cycle
        cnt = 0


        #run loop until all vertices are added
        while queue:
            u = queue.pop(0)
            top_order.append(u)

            #remove edges outgoing from u
            for vertex in self.graph[u]:
                in_degree[vertex] -= 1

                #new vertices which are "roots" get added to the queue
                if in_degree[vertex] == 0:
		            queue.append(vertex)
	        cnt += 1

        if cnt != self.V:
            print "No topolocial ordering exists."

        else:
            print top_order

        

       
	
#Normal case
g= Graph(6)
g.addEdge(5, 2);
g.addEdge(5, 0);
g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);
 
print "Following is a Topological Sort of the given graph"
g.topological_sort()



# Cyclic graph
g2= Graph(6)
g2.addEdge(5, 2);
g2.addEdge(2, 5);
g2.addEdge(4, 0);
g2.addEdge(4, 1);
g2.addEdge(2, 3);
g2.addEdge(3, 1);
g2.addEdge(5, 0);
 
print "Following is a Topological Sort of the given graph"
g2.topological_sort()

