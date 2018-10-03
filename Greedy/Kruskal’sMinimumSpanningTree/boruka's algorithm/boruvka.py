
# Boruvka's algorithm to find Minimum Spanning 
# Tree of a given connected, undirected and weighted graph 
  
from collections import defaultdict 
  
#Class to represent a graph 
class Graph: 
  
    def __init__(self,vertices): 
        self.V= vertices #No. of vertices 
        self.graph = [] # default dictionary to store graph 
          
   
    # function to add an edge to graph 
    def addEdge(self,u,v,w): 
        self.graph.append([u,v,w]) 
  
    # A utility function to find set of an element i 
    # (uses path compression technique) 
    def find(self, parent, i): 
        if parent[i] == i: 
            return i 
        return self.find(parent, parent[i]) 
  
    # A function that does union of two sets of x and y 
    # (uses union by rank) 
    def union(self, parent, rank, x, y): 
        xroot = self.find(parent, x) 
        yroot = self.find(parent, y) 
  
        # Attach smaller rank tree under root of high rank tree 
        # (Union by Rank) 
        if rank[xroot] < rank[yroot]: 
            parent[xroot] = yroot 
        elif rank[xroot] > rank[yroot]: 
            parent[yroot] = xroot 
        #If ranks are same, then make one as root and increment 
        # its rank by one 
        else : 
            parent[yroot] = xroot 
            rank[xroot] += 1
  
    # The main function to construct MST using Kruskal's algorithm 
    def boruvkaMST(self): 
        parent = []; rank = [];  
  
        # An array to store index of the cheapest edge of 
        # subset. It store [u,v,w] for each component 
        cheapest =[] 
  
        # Initially there are V different trees. 
        # Finally there will be one tree that will be MST 
        numTrees = self.V 
        MSTweight = 0
  
        # Create V subsets with single elements 
        for node in range(self.V): 
            parent.append(node) 
            rank.append(0) 
            cheapest =[-1] * self.V 
      
        # Keep combining components (or sets) until all 
        # compnentes are not combined into single MST 
  
        while numTrees > 1: 
  
            # Traverse through all edges and update 
               # cheapest of every component 
            for i in range(len(self.graph)): 
  
                # Find components (or sets) of two corners 
                # of current edge 
                u,v,w =  self.graph[i] 
                set1 = self.find(parent, u) 
                set2 = self.find(parent ,v) 
  
                # If two corners of current edge belong to 
                # same set, ignore current edge. Else check if  
                # current edge is closer to previous 
                # cheapest edges of set1 and set2 
                if set1 != set2:      
                      
                    if cheapest[set1] == -1 or cheapest[set1][2] > w : 
                        cheapest[set1] = [u,v,w]  
  
                    if cheapest[set2] == -1 or cheapest[set2][2] > w : 
                        cheapest[set2] = [u,v,w] 
  
            # Consider the above picked cheapest edges and add them 
            # to MST 
            for node in range(self.V): 
  
                #Check if cheapest for current set exists 
                if cheapest[node] != -1: 
                    u,v,w = cheapest[node] 
                    set1 = self.find(parent, u) 
                    set2 = self.find(parent ,v) 
  
                    if set1 != set2 : 
                        MSTweight += w 
                        self.union(parent, rank, set1, set2) 
                        print ("Edge %d-%d with weight %d included in MST" % (u,v,w)) 
                        numTrees = numTrees - 1
              
            #reset cheapest array 
            cheapest =[-1] * self.V 
  
              
        print ("Weight of MST is %d" % MSTweight) 
                            
  
      
g = Graph(4) 
g.addEdge(0, 1, 10) 
g.addEdge(0, 2, 6) 
g.addEdge(0, 3, 5) 
g.addEdge(1, 3, 15) 
g.addEdge(2, 3, 4) 
  
g.boruvkaMST() 