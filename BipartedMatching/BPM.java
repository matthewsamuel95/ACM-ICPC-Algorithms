import java.util.*;
import java.io.*;
import java.lang.*;

public class BPM
{
	public static int NIL = 0;
	public static int INF = Integer.MAX_VALUE;
	
	private int m,n;
	private ArrayList<Integer> adj[];
	private int[] pairU;
	private int[] pairV;
	private int[] dist;
	
	public BPM(int m,int n)
	{
		this.m = m;
		this.n = n;
		adj = new ArrayList[m+1];
		for(int i=0;i<=m;i++)
			adj[i] = new ArrayList<Integer>();
	}
	
	public void addEdge(int u,int v)
	{
		adj[u].add(v);
	}
	
	public boolean BFS()
	{
		Queue<Integer> q = new LinkedList<Integer>();
		for(int u=1;u<=m;u++)
		{
			if(pairU[u]==NIL)
			{
				dist[u] = 0;
				q.add(u);
			}
			else
				dist[u] = INF;
		}
		
		dist[NIL] = INF;
		while(!q.isEmpty())
		{
			int u = q.poll();
			if(dist[u]<dist[NIL])
			{
				for(int v : adj[u])
				{
					if(dist[pairV[v]]==INF)
					{
						dist[pairV[v]] = dist[u]+1;
						q.add(pairV[v]);
					}
				}
			}
		}
		return (dist[NIL]!=INF);
	}
	
	public boolean augPath(int u)
	{
		if(u!=NIL)
		{
			for(int v : adj[u])
			{
				if(dist[pairV[v]] == (dist[u] + 1))
				{
					if(augPath(pairV[v]))
					{
						pairV[v] = u;
						pairU[u] = v;
						return true;
					}
				}
			}			
			dist[u] = INF;
			return false;
		}
		return true;
	}
	
	public int maxM()
	{
		pairU = new int[m+1];
		pairV = new int[n+1];
		
		
		dist = new int[m+1];
		for(int i=0;i<=m;i++)
			pairU[i] = NIL;
		for(int i=0;i<=n;i++)
			pairV[i] = NIL;
		
		int result = 0;
		while(BFS())
		{
			for(int u=1;u<=m;u++)
			{
				if(pairU[u]==NIL && augPath(u))
					result++;
			}
		}
		return result;
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the vertex on left side of graph");
		int m = in.nextInt();
		
		System.out.println("Enter the vertex on right side of graph");
		int n = in.nextInt();
		
		System.out.println("Enter the numebr of edges");
		int edges = in.nextInt();
		
		BPM bpm = new BPM(m,n);
		for(int i=0;i<edges;i++)
		{
			int u = in.nextInt();
			int v = in.nextInt();
			bpm.addEdge(u, v);			
		}
		
		System.out.println("Maximum matching is: " + bpm.maxM());
	}
}
