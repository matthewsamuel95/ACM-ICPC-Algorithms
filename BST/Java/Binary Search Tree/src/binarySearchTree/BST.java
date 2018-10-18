package binarySearchTree;

public class BST {

	private Node node;
	private Node root;
	
	public void addElement(Node newNode, int key){
		newNode = new Node(key);
		
		if (newNode != null) {
			if(node.equals(null)){
				node = newNode;
				root = node;
			} else if(newNode.getKey() < node.getKey()){
				if(node.getLeftChild() != null){
					addElement(node.getLeftChild(), key);
				} else {
					node.setLeftChild(newNode);
					newNode.setParent(node);
				}
			} else if(newNode.getKey() > node.getKey()){
				if(node.getRightChild() != null){
					addElement(node.getRightChild(), key);
					newNode.setParent(node);
				} else {
					node.setRightChild(newNode);
				}
			} else System.out.println("Element is already in this structure");
		}
	}
	
	public Node binarySearch(Node searchElement, Node node){
		if(root != null && searchElement != null){
			while(searchElement.getKey() != node.getKey()){
			if(searchElement.getKey() < node.getKey()){
				binarySearch(searchElement, node.getLeftChild());
				} else if (searchElement.getKey() > node.getKey()){
					binarySearch(searchElement, node.getRightChild());
				} else return node;
			}
		}
		return null;
	}
	
	public void preOrder(Node root){
		if(root != null){
			System.out.println(root.getKey() + " ");
			preOrder(root.getLeftChild());
			preOrder(root.getRightChild());
		}
	}
	
	public void order(Node root){
		if(root != null){
			order(root.getLeftChild());
			System.out.println(root.getKey() + " ");
			order(root.getRightChild());
		}
	}
	
	public void postOrder(Node root){
		if(root != null){
			postOrder(root.getLeftChild());
			postOrder(root.getRightChild());
			System.out.println(root.getKey() + " ");
		}
	}
	
}
