// Class for Doubly Linked List 
public class DLL { 
    Node head; // head of list 
  
    /* Doubly Linked list Node*/
    class Node { 
        int data; 
        Node prev; 
        Node next; 
  
        // Constructor to create a new node 
        // next and prev is by default initialized as null 
        Node(int d) { data = d; } 
    } 
} public void InsertAfter(Node prev_Node, int new_data) 
{ 
  
    
    if (prev_Node == null) { 
        System.out.println("The given previous node cannot be NULL "); 
        return; 
    } 
  
    
    Node new_node = new Node(new_data); 
  
    
    new_node.next = prev_Node.next; 
  
    
    prev_Node.next = new_node; 
  
    
    new_node.prev = prev_Node; 
  
    
    if (new_node.next != null) 
        new_node.next.prev = new_node; 
} 
