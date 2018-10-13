import java.util.ArrayList;
import java.util.Scanner;

public class lca {
  private final static int max = 100;
  private final static int height_max = 7;

  int n;

  private int[][] parent = new int[max][height_max]; //parent[v][k]: (2^k)-th ancestor of v
  private int[] level = new int[max]; //level counting from root
  private int[] log = new int[max]; //log[i] := [log_2(i)]
  //Incidence matrix of graph.
  private ArrayList<ArrayList<Integer>> graph = new ArrayList<>(max);

  //pre-calculate [log_2(i)] for all i<max
  void updateLog() {
    for (int i = 2; i < max; i++) {
      log[i] = log[i / 2] + 1;
    }
  }

  /* Set v as a parent of all the neighbors except p.
   * Repeat the step with dfs
   */
  void dfsForParentAndLevels(int v, int p) {
    for (int sibling : graph.get(v)) {
      if (sibling != p) {
        //We are traversing away from the root.
        level[sibling] = level[v] + 1;
        //First(2^0-th) parent of sibling is v.
        parent[sibling][0] = v;
        dfsForParentAndLevels(sibling, v);
      }
    }
  }

  void updateParents() {
    for (int k = 1; k <= log[n]; k++) {
      for (int v = 1; v <= n; v++) {
        parent[v][k] = parent[parent[v][k - 1]][k - 1];
        //(2^k)-th parent of v: 2^(k-1)-th parent of {2^(k-1)-th parent of v}
      }
    }
  }

  //returns the lca of pair (u,v)
  int lca(int u, int v) {
    //We assume u is farther than v.
    if (level[u] < level[v]) {
      return lca(v, u);
    }
    //lca(u,v) is same as lca(u's 2^k-th parent, v),
    //as long as that parent is sits lower level than v.
    //so we can replace u with that parent.
    //we start with as biggest jump as possible.
    for (int k = log[n]; k >= 0; k--) {
      if (level[u] - (1 << k) >= level[v]) {
        u = parent[u][k];
      }
    }
    if (u == v) {
      //if we come to v after some possible jumps above
      //that means v is a direct ancestor of u. So the lca is v.
      return u;
    }
    //Now u and v are on the same level.
    //Again we start with the biggest possible jump.
    for (int k = log[n]; k >= 0; k--) {
      if (parent[u][k] != parent[v][k]) {
        //They must ascend together, until they have common parent.
        u = parent[u][k];
        v = parent[v][k];
      }
    }
    return parent[u][0];
  }

  private void run() {
    final Scanner scan = new Scanner(System.in);

    updateLog();
    int x, y;
    System.out.println("Let's build the tree first.\nEnter number of vertices: ");
    n = scan.nextInt();
    for (int i = 0; i <= n ; i++) {
      graph.add(new ArrayList<>());
    }

    System.out.println("\nEnter " + (n-1) + " edge information, with 1-indexed. (u v)");
    for (int i = 1; i < n ; i++) {
      x = scan.nextInt();
      y = scan.nextInt();
      graph.get(x).add(y);
      graph.get(y).add(x);
    }

    //mark vertex 1 as a root.
    //We set 1(itself) as its parent.
    dfsForParentAndLevels(1, 1);
    updateParents();

    System.out.println("\nEnter the pair for lca: ");
    x = scan.nextInt();
    y = scan.nextInt();

    System.out.println(lca(x, y) + "\n");
  }

  public static void main(String[] args) {
    new lca().run();
  }

}
