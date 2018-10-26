import java.util.*;
import java.lang.*;

class bfs
{  
   private Queue<Node> queue;
	static ArrayList<Node> nodes=new ArrayList<Node>();
	static class Node
	{
		int data;
		boolean visited;
		List<Node> neighbours;
 
		Node(int data)
		{
			this.data=data;
			this.neighbours=new ArrayList<>();
 
		}
		public void addneighbours(Node neighbourNode)
		{
			this.neighbours.add(neighbourNode);
		}
		public List<Node> getNeighbours() {
			return neighbours;
		}
		public void setNeighbours(List<Node> neighbours) {
			this.neighbours = neighbours;
		}
	}
 
	public bfs()
	{
		queue = new LinkedList<Node>();
	}
 
	public void bfs_node(Node node)
	{
		queue.add(node);
		node.visited=true;
		while (!queue.isEmpty())
		{
 
			Node element=queue.remove();
			System.out.print(element.data + "t");
			List<Node> neighbours=element.getNeighbours();
			for (int i = 0; i < neighbours.size(); i++) {
				Node n=neighbours.get(i);
				if(n!=null && !n.visited)
				{
					queue.add(n);
					n.visited=true;
 
				}
			}
 
		}
	}
 
    
    public static void main(String args[])
    {
        Node node40 =new Node(40);
		Node node10 =new Node(10);
		Node node20 =new Node(20);
		Node node30 =new Node(30);
		Node node60 =new Node(60);
		Node node50 =new Node(50);
		Node node70 =new Node(70);
 
		node40.addneighbours(node10);
		node40.addneighbours(node20);
		node10.addneighbours(node30);
		node20.addneighbours(node10);
		node20.addneighbours(node30);
		node20.addneighbours(node60);
		node20.addneighbours(node50);
		node30.addneighbours(node60);
		node60.addneighbours(node70);
		node50.addneighbours(node70);
		System.out.println("The BFS traversal of the graph is ");
		bfs bfsExample = new bfs();
		bfsExample.bfs_node(node40);
 		System.out.println("");
	}
}



