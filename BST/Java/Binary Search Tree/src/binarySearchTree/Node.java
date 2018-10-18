package binarySearchTree;

public class Node {
	
	private Node leftChild, rightChild, parent;
	
	private int key;
	
	public Node( int key){
		this.key = key;
	}
	
	public int getKey(){
		return this.key;
	}
	
	public Node getLeftChild(){
		return this.leftChild;
	}
	
	public Node getRightChild(){
		return this.rightChild;
	}
	
	public Node getParent(){
		return this.parent;
	}
	
	public void setLeftChild(Node leftChild){
		this.leftChild = leftChild;
	}
	
	public void setRightChild(Node rightChild){
		this.rightChild = rightChild;
	}
	
	public void setParent(Node parent){
		this.parent = parent;
	}

}
