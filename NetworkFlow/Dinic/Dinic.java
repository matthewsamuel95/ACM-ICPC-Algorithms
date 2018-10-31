/**
 * @author dbatchunag
 */

import java.util.*;

public class Dinic {

  private class Graph {
    final int V;
    int source;
    int sink;

    final ArrayList<ArrayList<Integer>> graph; // Graph adjacency list
    final ArrayList<Edge> edges;
    final int[] distFromSource; // Shortest distance from source in level graph

    private class Edge {
      final int start;
      final int end;
      final int capacity;
      int flow;
      Edge(int u, int v, int capacity, int flow) {
        this.start = u;
        this.end = v;
        this.capacity = capacity;
        this.flow = flow;
      }
    }

    Graph(int numVertices) {
      V = numVertices;
      graph = new ArrayList<>();
      for (int i=0; i<V; i++){
        graph.add(new ArrayList<>());
      }
      distFromSource = new int[V];
      edges = new ArrayList<>();
    }

    void addEdge(int v1, int v2, final int capacity) {
      v1 -=1; // Remove these decrements if
      v2 -=1; // vertexes are numbered from zero
      final Edge e1 = new Edge(v1, v2, capacity, 0);
      final Edge e2 = new Edge(v2, v1, 0, 0);
      graph.get(v1).add(edges.size());
      edges.add(e1);
      graph.get(v2).add(edges.size());
      edges.add(e2);
    }

    private int dinic(final int source, final int sink) {
      this.source = source -1;
      this.sink = sink - 1;
      int flow = 0;
      //Repeat while sink is reachable from source in level graph
      while (bfs()) {
        final int[] remaining = new int[V];
        while (true) {
          final int pushed = dfs(this.source, Integer.MAX_VALUE, remaining);
          if (pushed==0) {
            break;
          }
          flow += pushed;
        }
      }
      return flow;
    }

    boolean bfs() {
      Arrays.fill(distFromSource, -1);
      distFromSource[source]=0;

      final Deque<Integer> queue= new ArrayDeque<>();
      queue.add(source);
      //Find the shortest path to sink in level graph
      while (!queue.isEmpty() && (distFromSource[sink] == -1)) {
        final int u = queue.pop();
        for (final int vId : graph.get(u)) {
          final Edge uv = edges.get(vId);
          final int v = uv.end;
          if ((distFromSource[v] == -1) && (uv.flow < uv.capacity)) {
            queue.addLast(v);
            distFromSource[v] = distFromSource[u] + 1;
          }
        }
      }
      return distFromSource[sink] != -1;
    }

    // Finding the blocking flow
    // `minflow` is a minimal capacity on the path of the level graph
    // remaining[u] is a number of [u's] neighbors in adjacency list, that was not removed
    int dfs(final int u, final int minflow, final int[] remaining) {
      if (minflow == 0) {
        return 0;
      }
      if (u == sink) {
        return minflow;
      }
      for (; remaining[u] < graph.get(u).size(); remaining[u]++) {
        final int vId = graph.get(u).get(remaining[u]);
        final Edge uv = edges.get(vId);
        final int v = uv.end;
        if (distFromSource[v] != distFromSource[u] + 1) {
          continue;
        }
        final int pushed = dfs(v, Math.min(minflow, uv.capacity - uv.flow), remaining);
        if (pushed>0) {
          edges.get(vId).flow += pushed;
          //Backward edge
          edges.get(vId ^ 1).flow -= pushed;
          return pushed;
        }
      }
      return 0;
    }
  }

  private void run() {
    final Graph g = new Graph(4); // Create graph with 4 vertexes

    g.addEdge(1, 2, 1); // [1] --(1)--> [2]
    g.addEdge(1, 3, 2); // [1] --(2)--> [3]
    g.addEdge(3, 2, 1); // [3] --(1)--> [2]
    g.addEdge(2, 4, 2); // [2] --(2)--> [4]
    g.addEdge(3, 4, 1); // [3] --(1)--> [4]

    System.out.println(String.format("The maximum possible flow (from 1 to 4) is %d",g.dinic(1, 4)));
    System.out.println("Answer should be 3");
  }

  public static void main(String[] args) {
    new Dinic().run();
  }

}

