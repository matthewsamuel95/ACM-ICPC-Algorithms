/**
 * @author dbatchunag
 */

import java.util.*;

public class FordFulkerson {
  private final int V = 6;

  //Check if there is a path from source to target in residue graph.
  private boolean bfs(final int[][] resGraph, final int source, final int target, final int[] parent)
  {
    // Create a visited array and mark all vertices as not visited
    final boolean[] visited = new boolean[V];

    // Create a queue, enqueue source vertex
    // and mark source vertex as visited
    final Deque<Integer> queue= new ArrayDeque<>();
    //We start from s, marking as visited.
    queue.push(source);
    visited[source] = true;
    parent[source] = -1;

    // Standard BFS Loop
    while (!queue.isEmpty()) {
      final int u = queue.pollFirst();

      for (int v=0; v<V; v++) {
        if (!visited[v] && resGraph[u][v] > 0) {
          //Put the neighbors to the queue
          queue.push(v);
          //keep track for augmenting path
          parent[v] = u;
          visited[v] = true;
        }
      }
    }
    //augmenting path is found
    return visited[target];
  }

  private int fordFulkerson(final int[][] graph, final int source, final int target)
  {
    final int[][] residualGraph = graph.clone();
    final int[] parent= new int[V];

    int max_flow = 0;

    // Augment the flow while there is path from source to sink
    while (bfs(residualGraph, source, target, parent))
    {
      //augmenting path can be constructed through parent
      int path_flow = Integer.MAX_VALUE;
      for (int v=target; v!=source; v=parent[v]) {
        final int u = parent[v];
        //get the maximum possible size augmenting flow
        path_flow = Math.min(path_flow, residualGraph[u][v]);
      }

      //update the graph
      for (int v=target; v != source; v=parent[v]) {
        final int u = parent[v];
        residualGraph[u][v] -= path_flow;
        residualGraph[v][u] += path_flow;
      }

      max_flow += path_flow;
    }

    return max_flow;
  }

  private void run() {
    // Let us create a graph shown in the above example
    final int[][] graph = new int[][] {
      {0, 16, 13, 0, 0, 0},
      {0, 0, 10, 12, 0, 0},
      {0, 4, 0, 0, 14, 0},
      {0, 0, 9, 0, 0, 20},
      {0, 0, 0, 7, 0, 4},
      {0, 0, 0, 0, 0, 0}
    };

    System.out.println(String.format("The maximum possible flow is %d", fordFulkerson(graph, 0, 5)));
  }

  public static void main(String[] args) {
    new FordFulkerson().run();
  }

}

