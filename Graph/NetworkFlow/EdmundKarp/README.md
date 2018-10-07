# EDMUND KARP ALGORITHM
The Edmonds-Karp Algorithm is a specific implementation of the Ford-Fulkerson algorithm. Like Ford-Fulkerson, Edmonds-Karp is also an algorithm that deals with the max-flow min-cut problem.

Ford-Fulkerson is sometimes called a method because some parts of its protocol are left unspecified. Edmonds-Karp, on the other hand, provides a full specification. Most importantly, it specifies that breadth-first search should be used to find the shortest paths during the intermediate stages of the program.

Edmonds-Karp differs from Ford-Fulkerson in that it chooses the next augmenting path using breadth-first search (bfs). So, if there are multiple augmenting paths to choose from, Edmonds-Karp will be sure to choose the shortest augmenting path from the source to the sink.

## PSEUDOCODE
```
inputs
    C[n x n] : Capacity Matrix
    E[n x n] : Adjacency Matrix
    s : source
    t : sink
output
    f : maximum flow
Edmonds-Karp:
    f = 0                // Flow is initially 0
    F = [n x n]       // residual capacity array
    while true:
        m, P = Breadth-First-Search(C, E, s, t, F)
        if m = 0:
            break
        f = f + m
        v = t
        while v != s:
            u = P[v]
            F[u, v] = F[u, v] - m       //This is reducing the residual capacity of the augmenting path
            F[v, u] = F[v, u] + m        //This is increasing the residual capacity of the reverse edges 
            v = u
    return f
```