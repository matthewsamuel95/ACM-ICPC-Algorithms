
public class Node {
	private Object content;
	Node nextNode;
	
	public Node() {
		content = null;
		nextNode = null;
	}
	
	public Node(Object content) {
		this.content = content;
		nextNode = null;
	}
	
	public Object getContent() {
		return content;
	}
	
	public Node getNextNode() {
		return nextNode;
	}
	
	public void setNextNode(Node nextNode) {
		this.nextNode = nextNode;
	}
	
	public boolean hasNextNode() {
		return nextNode != null;
	}
}
