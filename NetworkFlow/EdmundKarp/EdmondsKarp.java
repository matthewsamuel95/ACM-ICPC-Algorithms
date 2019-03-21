/**
 * @author dbatchunag
 */

import java.util.*;

public class EdmondsKarp {

  private int maxFlowEdmondsKarp(final int [][]edges, final int[][] capacity, final int source, final int target) {
    final int n = capacity.length;
    int maxFlow = 0;
    final int[][] resGraph = new int [n][n];
    while (true) {
      //backtrack for augmenting path
      final int[] parent = new int[n];
      Arrays.fill(parent, -1);
      parent[source] = -2;

      //parent is updated during the bfs
      final int pathFlow = getAugmentingPath(edges, capacity, source, target, resGraph, parent);
      if (pathFlow == 0) {
        //No augmenting path is found
        break;
      }
      maxFlow += pathFlow;
      int v = target;
      while (v != source) {
        //traverse along the backtrack
        final int u = parent[v];
        resGraph[u][v] = resGraph[u][v] + pathFlow;
        resGraph[v][u] = resGraph[v][u] - pathFlow;
        v = u;
      }
    }
    return maxFlow;
  }

  //Returns
  private int getAugmentingPath(final int[][] edges,
                                final int[][] capacity,
                                final int source,
                                final int target,
                                final int[][] resGraph,
                                final int[] parent) {
    final int n = capacity.length;
    final int[] maxFlow = new int[n];
    maxFlow[source] = Integer.MAX_VALUE;

    final Deque<Integer> bfsQueue = new ArrayDeque<Integer>();
    bfsQueue.add(source);

    while (bfsQueue.size()> 0) {
      final int u = bfsQueue.pop();
      for (final int v : edges[u]) {
        if (capacity[u][v] - resGraph[u][v] > 0 && parent[v] == -1) {
          //we may use edge u->v (on source ~> .. ~> target)
          parent[v] = u;
          //Maximum possible flow size from source to v is computed below.
          maxFlow[v] = Math.min(maxFlow[u], capacity[u][v] - resGraph[u][v]);
          if (v != target) {
            bfsQueue.add(v);
          } else {
            //Path found
            return maxFlow[target];
          }
        }
      }
    }
    return 0;
  }


  private void run() {
    // Adjacency Matrix
    int [][] edges = new int[][]{{1, 2}, {2, 3}, {3}, {}};
    // Capacity Matrix
    int [][] capacity = new int[][]{
      {0, 1000000, 1000000, 0},
      {0, 0, 1, 1000000},
      {0, 0, 0, 1000000},
      {0, 0, 0, 0}
    };
    final int source = 0;
    final int target = 3;

    System.out.println(String.format("The maximum possible flow is %d", maxFlowEdmondsKarp(edges, capacity, source, target)));
  }

  public static void main(String[] args) {
    new EdmondsKarp().run();
  }

}

