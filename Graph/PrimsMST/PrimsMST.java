import java.util.*;

/**
 * @author dbatchunag
 */

public class PrimsMST {

  class Node implements Comparable<Node> {
    final int index;
    int distance;
    int parent;
    Node(int index, int distance, int parent) {
      this.index = index;
      this.distance = distance;
      this.parent = parent;
    }

    @Override
    public int compareTo(Node other) {
      return distance - other.distance;
    }
  };

  // A utility function to print the constructed MST stored in parent[]
  void printMST(final int parent[], final int [][] graph) {
    final int V = graph.length;
    int minCost = 0;
    System.out.println("Edge   Weight");
    for (int i = 0; i < V; i++) {
      if (parent[i]==-1) {
        //it's our root
        continue;
      }
      final int cost = graph[i][parent[i]];
      System.out.println(String.format("%d - %d    %d", parent[i], i, cost));
      minCost += cost;
    }
    System.out.println(String.format("Total Cost: %d", minCost));
  }

  void primMST(final int[][] graph) {
    final int V = graph.length;
    final int [] parent = new int[V]; // Backtrack array to construct MST back

    // Keep track of vertices that already covered
    final boolean[] covered = new boolean[V];
    //Priority queue for getting closest uncovered vertex
    final PriorityQueue<Node> priorityQueue = new PriorityQueue<>();

    //We can start with any node as a root
    final int root = (int) (Math.random() * V);
    priorityQueue.add(new Node(root, 0, -1));

    // We continue until we check all possibilities.
    while (!priorityQueue.isEmpty()) {
      // Pick the closest vertex from current sub-MST
      final Node node = priorityQueue.poll();
      final int u = node.index;
      if (!covered[u]) {
        covered[u] = true;
        parent[u] = node.parent;
        for (int v = 0; v < V; v++) {
          // This process could be faster if we use adjacency list.
          if (graph[u][v] > 0 && !covered[v]) {
            priorityQueue.add(new Node(v, graph[u][v], u));
          }
        }
      }
    }

    // print the constructed MST
    printMST(parent, graph);
  }


  private void run() {
     /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
    final int [][] graph = new int[][] {
      {0, 2, 0, 6, 0},
      {2, 0, 3, 8, 5},
      {0, 3, 0, 0, 7},
      {6, 8, 0, 0, 9},
      {0, 5, 7, 9, 0},
    };

    primMST(graph);
    System.out.println("\nAnswer should be 16");
  }

  public static void main(String[] args) {
    new PrimsMST().run();
  }

}

