package dsa;

public class Node {
	int data;
	
	Node next;
	Node head;
	Node t;
	Node() {
	}
		Node(int d) {
		data = d;
		next = null;
	}
//============LinkedList==============
//============Insertion===============
	public void insertAtFront(int data) {

		Node n = new Node(data);
		if (head == null) {
			head = n;
		} else {
			n.next = head;
			head = n;
		}

	}

	public void insertAtLast(int data) {

		Node n = new Node(data);
		Node t;
		t = head;
		while (t.next != null) {
			t = t.next;
		}
		t.next = n;
		n.next = null;
	}

	public void InsertAtPos(int index, int data) {
		Node n = new Node(data);
		Node no = head;
		for (int i = 0; i < index - 1; i++) {
			no = no.next;
			n.next = no.next;
			no.next = n;
		}
	}

//=========print function===========
	public void printList() {
		Node n = head;
		System.out.print("|");
		while (n != null) {
			System.out.print(" "+n.data + " |");
			
			n = n.next;
		}
		System.out.println("");
	}

//===========Extra Stuff ===========
	public void isEmpty() {
		if (head == null)
			System.out.println("List is empty");
		else
			System.out.println("List contains nodes");
	}

//===========deletion==============
	public void delAtFirst() {

		if (head == null) {
			System.out.println("List is empty");
		} else {
			Node t = head;
			{
				while (t.next == head) {
					t = t.next;
				}
				t.next = head.next;
				head = head.next;
			}
		}
	}

	public void delAtLast() {
		if (head == null) {
			System.out.println("List is empty");
		}
		else {
			t=head;
			while((t.next).next!=null) {
				t=t.next;
			}
			t.next=null;
		}
	}
	
	public void delAtPos(int pos) {
		if(head==null) {
			System.out.println("List is empty");
		}
		else
		{t=head;
		while(--pos>1)
		{t=t.next;}
		Node p=t.next;
		t.next=t.next.next;
		p.next=null;
		}
	}
	//======================endofLinkedList=======================================
	
//=====================DoubleLinkedList=====================
	
	//=====================circleList=====================
	//=====================DoubleLinkedList=====================
	
	
	
	
	
	
}



