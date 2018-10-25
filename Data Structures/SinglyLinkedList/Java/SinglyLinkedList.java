
/**
 * A generic singly linked list implementation that takes any kind of object.
 */
public class SinglyLinkedList {
	Node head;
	
	public SinglyLinkedList() {
		head = null;
	}
	
	public void add(Object elementContent) {
		if (head != null) {
			Node temp = new Node(elementContent);
			temp.setNextNode(head);
			head = temp;
		} else {
			head = new Node(elementContent);
		}
	}
	
	// TODO: Needs node deletion method or some way of doing that
	
	public Node getHeadNode() {
		return head;
	}
	
	@Override
	public String toString() {
		String result = "";
		if (head != null) {
			Node currentNode = head;
			result += currentNode.getContent();
			while (currentNode.hasNextNode()) {
				currentNode = currentNode.getNextNode();
				result += ", " + currentNode.getContent();
			}
		}
		return result;
	}
}
