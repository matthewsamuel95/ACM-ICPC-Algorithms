# BRANCH AND BOUND


- **Branch and bound (BB, B&B, or BnB)** is an algorithm design paradigm for discrete and combinatorial optimization problems, as well as mathematical optimization.
A branch-and-bound algorithm consists of a systematic enumeration of candidate solutions by means of **state space search:** the set of candidate solutions is 
thought of as forming a rooted tree with the full set at the root.

- The algorithm explores branches of this tree, which represent subsets of the solution set. Before enumerating the candidate solutions of a branch, 
the branch is checked against upper and lower estimated bounds on the optimal solution, and is discarded if it cannot produce a better solution than the best one found so far by the algorithm.

1. The term branch-and-bound refers to all state space search methods in which all children of the £-node are generated before any other live node can
  become the £-node.
2. We have already seen two graph search strategies, BFS and D-search, in which the exploration of a new node cannot begin until the node currently
  being explored is fully explored.
3. Both of these generalize to branch-and-bound strategies.
	- In branch-and-bound terminology, a BFS-like state space search will be called FIFO (First In First Out) 
          search as the list of live nodes is a first-in-first-out list (or queue).
	
	- A D-search-like state space search will be called LIFO (Last In First Out)
	  search as the list of live nodes is a last-in-first-out list (or stack
