import java.util.Arrays;
import java.util.Scanner;

public class KruskalsMinimumSpanningTree {
    int V;
    int E; //Number of vertices and edges in the graph
    Edge[] edge;
    Edge[] mst; //Array of Edge holds the entire graph and mst array holds the Edges that are in the mst
    int[] parent; //Disjoint-set
    int[] size; //Size array for size of set

    public static class Edge implements Comparable<Edge> {
        //beginning vertex, ending vertex, weight of edge
        int bv;
        int ev;
        int cost;

        //Empty constructor
        public Edge() {
            //to initialize arrays later
        }

        //Full constructor
        public Edge(int bv, int ev, int cost) {
            this.bv = bv;
            this.ev = ev;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge other) {
            return this.cost - other.cost;
        }
    }

    public KruskalsMinimumSpanningTree(int v, int e) {
        V = v;
        E = e;

        edge = new Edge[e];
        for (int i = 0; i < e; i++) {
            edge[i] = new Edge();
        }

        mst = new Edge[v - 1];
        for (int i = 0; i < v - 1; i++) {
            mst[i] = new Edge();
        }

        parent = new int[v];
        for (int i = 0; i < v; i++) {
            parent[i] = -1;
        }

        size = new int[v];
        for (int i = 0; i < v; i++) {
            size[i] = 1;
        }
    }

    public int find(int v) {
        if (parent[v] == -1) { // if -1 it is the root/parent
            return v; //the vertex is already the parent
        } else {
            return find(parent[v]); //if it's not the parent, keep using find to find the parent
        }
    }

    public void union(int bv, int ev) {
        int pb = find(bv); //parent of beginning vertex
        int pe = find(ev); //parent of beginning vertex

        if (size[pb] < size[pe]) { //if the size of one set is greater than the other
            /*
             * set the parent of the smaller set to the parent of the larger set,
             * we're attaching the ENTIRE smaller set from its parent vertex to
             * the parent vertex of the larger set.
             */
            parent[pb] = pe;
            /*
             * add the size of the smaller set to the size of the
             * larger set (since they're 1 set now)
             */
            size[pe] += size[pb];
        } else {
            //same procedure as above
            parent[pe] = pb;
            size[pb] += size[pe];
        }
    }

    public static void main(String[] args) {
        //Create a Scanner so we can input the information about edges
        Scanner sc = new Scanner(System.in);

        //Let's input how many vertices and edges we're given
        int v = sc.nextInt();
        int e = sc.nextInt();

        //Create a new object of your Main class, let's call it "graph"
        //and pass in the parameters v (vertices) and e (edges)
        //The constructor of the Main class will initialize all our
        //arrays for us.
        KruskalsMinimumSpanningTree graph = new KruskalsMinimumSpanningTree(v, e);

        //Using a for-loop, input the information about each edge
        for (int i = 0; i < e; i++) {
            int bv = sc.nextInt(); //beginning vertex
            int ev = sc.nextInt(); //ending vertex
            int cost = sc.nextInt();
            //Now let's use the 2nd constructor of the Edge class
            //and put the above information into our Edge array
            graph.edge[i] = new Edge(bv, ev, cost);
        }

        //Using Arrays.sort(), we make use of the Comparable interface
        //we implemented in the Edge class
        Arrays.sort(graph.edge);

        //Create a count variable to keep track of the edges we've added
        int count = 0;
        //Create a for-loop to loop through all the given edges
        //we sorted earlier
        for (int i = 0; i < e; i++) {
            //Grab the details of the ith edge
            //it should be the edge with the least cost
            int bv = graph.edge[i].bv;
            int ev = graph.edge[i].ev;
            int cost = graph.edge[i].cost;

            //Using the find function we created earlier
            //for our disjoint-set, use it to find bv's root/parent
            //and ev's root/parent. Store in respective variables
            int pb = graph.find(bv); //parent of beginning vertex
            int pe = graph.find(ev); //parent of ending vertex

            //If the parent of bv and ev are not the same,
            //then the edge won't form a cycle
            if (pb != pe) {
                //Using the union function
                graph.union(bv, ev);

                //Add the edge to the MST array
                //Using count because not every given edge (i)
                //can be added to the MST
                graph.mst[count].bv = bv;
                graph.mst[count].ev = ev;
                graph.mst[count].cost = cost;

                //If the MST has V - 1 edges in it
                //then we have found the MST of the graph
                //WE'VE COMPLETED THE ALGORITHM!
                if (count == v - 1) {
                    break;
                }
            }
        }
        for (int i = 0; i < v - 1; i++) {
            System.out.print(graph.mst[i].bv + " ");
            System.out.print(graph.mst[i].ev + " ");
            System.out.println(graph.mst[i].cost);
        }
    }
}
