public class Node {

	private int data;
	private Node leftNode;
	private Node rightNode;

	public Node(int data) {
		this.data = data;
	}

	public int getData() {
		return data;
	}

	public Node getLeftNode() {
		return leftNode;
	}

	public Node getRightNode() {
		return rightNode;
	}

	public void setData(int data) {
		this.data = data;
	}

	public void setLeftNode(Node leftNode) {
		this.leftNode = leftNode;
	}

	public void setRightNode(Node rightNode) {
		this.rightNode = rightNode;
	}
}