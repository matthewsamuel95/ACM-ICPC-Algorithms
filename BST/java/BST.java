public class BST {

	private Node root;

	public boolean find(int data) {

		Node current = root;

		while(current != null) {
			if(current.getData() == data)
				return true;
			if(current.getData() < data)
				current = current.getRightNode();
			else
				current = current.getLeftNode();
		}

		return false;
	}


	public void insert(int data) {

		Node current = root;
		Node parent = root;
		boolean isLeftChild = false;

		if(root == null){
			root = new Node(data);
			return;
		}

		while(current != null) {
			parent = current;
			if(current.getData() == data)
				return;
			if(current.getData() < data) {
				current = current.getRightNode();
				isLeftChild = false;
			}
			else {
				current = current.getLeftNode();
				isLeftChild = true;
			}
		}

		if(isLeftChild) 
			parent.setLeftNode(new Node(data));
		else
			parent.setRightNode(new Node(data));
	}

	public boolean delete(int data) {

		Node parent = root;
		Node current = root; 

		if(current == null)
			return false;

		boolean isLeftChild = false;

		while(current.getData() != data) {

			parent = current;

			if(current.getData() < data) {
				current = current.getRightNode();
				isLeftChild = false;
			}
			else {
				current = current.getLeftNode();	
				isLeftChild = true;
			}

			if(current == null)
				return false;
		}

		//Node to be deleted has no children
		
		if(current.getLeftNode() == null && current.getRightNode() == null){
			if(current==root){
				root = null;
			}
			if(isLeftChild ==true){
				parent.setLeftNode(null);
			} else {
				parent.setRightNode(null);
			}
		}
		//Node to be deleted has only one child
		else if(current.getRightNode() == null){

			if(current == root){
				root = current.getLeftNode();
			} else if(isLeftChild) {
				parent.setLeftNode(current.getLeftNode());
			} else {
				parent.setRightNode(current.getLeftNode());
			}
		} else if(current.getLeftNode() == null){
			if(current == root){
				root = current.getRightNode();
			} else if(isLeftChild) {
				parent.setLeftNode(current.getRightNode());
			} else {
				parent.setRightNode(current.getRightNode());
			}
		} 

		// Node to be deleted has two children
		else if(current.getLeftNode() != null && current.getRightNode() != null) {
			
			//We have to find the min node in the right subtree
			Node successor = getSuccessor(current);
			if(current == root) {
				root = successor;
			} else if(isLeftChild) {
				parent.setLeftNode(successor);
			} else {
				parent.setRightNode(successor);
			}			
			successor.setLeftNode(current.getLeftNode());
		}		
		return true;		
	}

	public Node getSuccessor(Node deleteNode){

		Node successor = null;
		Node successorParent = null;
		Node current = deleteNode.getRightNode();
		while(current != null){
			successorParent = successor;
			successor = current;
			current = current.getLeftNode();
		}

		//check if successor has the right child (it cannot have left child for sure)
		// if it does have the right child, add it to the left of successorParent.

		if(successor != deleteNode.getRightNode()){
			successorParent.setLeftNode(successor.getRightNode());
			successor.setRightNode(deleteNode.getRightNode());
		}

		return successor;
	}

	private void display(Node root){
		if(root != null){
			display(root.getLeftNode());
			System.out.print(" " + root.getData());
			display(root.getRightNode());
		}
	}

	public void display(){
		display(root);
	}

	public static void main(String arg[]){
		BST b = new BST();
		b.insert(3);
		b.insert(8);
		b.insert(1);
		b.insert(4);
		b.insert(6);
		b.insert(2);
		b.insert(10);
		b.insert(9);
		b.insert(20);
		b.insert(25);
		b.insert(15);
		b.insert(16);
		System.out.println("Original Tree : ");
		b.display();		
		System.out.println("");
		System.out.println("Check whether Node with value 4 exists : " + b.find(4));
		System.out.println("Delete Node with no children (2) : " + b.delete(2));		
		b.display();
		System.out.println("\n Delete Node with one child (4) : " + b.delete(4));		
		b.display();
		System.out.println("\n Delete Node with Two children (10) : " + b.delete(10));		
		b.display();
	}
}