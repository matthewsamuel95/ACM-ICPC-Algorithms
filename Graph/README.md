# Graph



## Definition:

A Graph is a non-linear data structure consisting of nodes and edges. The nodes are sometimes also referred to as vertices and the edges are lines or arcs that connect any two nodes in the graph.

A Graph consists of a finite set of vertices(or nodes) and set of Edges which connect a pair of nodes.

In Mathematics, a graph is generally represented in the form G(V,E) where:

1. V is the finite set of vertices also called as nodes, of the graph G.

2. E is the finite set of pairs (u,v) callled as edge, of the graph G.

If these pairs are ordered, then the graph is a **directed graph(di-graph)**, otherwise it is an **undirected graph**.

**Undirected Graph**:

Pair (u,v) represents an edge connecting node 'u' and node 'v', and (u,v) is same as (v,u).

**Directed Graph**:

Pair (u,v) represents an edge from node 'u' to node 'v', i.e. the edge has a direction from 'u' to 'v'. Therefore (u,v) is not same as (v,u) in a directed graph.

## Graph and its Representations:

Following two are the most commonly used representations of a graph:

1. Adjacency Matrix

2. Adjacency List

**Adjacency Matrix:**

Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. 

![](https://www.oreilly.com/library/view/php-7-data/9781786463890/assets/image_09_012-1.jpg)

Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j and adj[i][j] = 0 indicates that there is no edge from vertex i to vertex j. Adjacency Matrix is also used to represent weighted graphs-(A graph having a weight, or number, associated with each edge.). If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w.

Adjacency matrix for undirected graph is always symmetric. 

**Adjacency List:**

![](https://i.stack.imgur.com/8PQ2E.png)

An array of lists is used. Size of the array is equal to the number of vertices. Let the array be array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. 

This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs.
