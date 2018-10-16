/*  This is a doubly linked list where each node has a previous or next pointer.  
    It allows adding and deleting of the first and last node.
*/

public class Deque<Item> {
  private int size;
  private Node first;
  private Node last;

  private class Node {
      Item item;
      Node prev;
      Node next;
  }

  public Deque() {
      first = null;
      last = null;
      size = 0;
  }

  public boolean isEmpty() {
      return size == 0;
  }

  public int size() {
      return size;
  }

  public void addFirst(Item item) {
      if (item == null) {
          throw new IllegalArgumentException("Item added to front is null");
      }

      Node oldFirst = first;
      first = new Node();
      first.item = item;
      first.prev = null;
      first.next = oldFirst;
      size++;

      // link next node to first node, if next node has data
      if (first.next != null) {
          oldFirst.prev = first;
      }

      if (size == 1) {
          last = first;
      } else if (size == 2) {
          // this equal last node
          last = oldFirst;
      }
  }

  public void addLast(Item item) {
      if (item == null) {
          throw new IllegalArgumentException("Item added to end is null");
      }

      Node oldLast = last;
      last = new Node();
      last.item = item;
      last.prev = oldLast;
      last.next = null;
      size++;

      // link prev node to last node, if prev node has data
      if (last.prev != null) {
          oldLast.next = last;
      }

      if (size == 1) {
          first = last;
      } else if (size == 2) {
          // this equal last node
          first = oldLast;
      }
  }

  public Item removeFirst() {
      if (isEmpty()) {
          throw new NoSuchElementException("Deque is empty");
      }

      Item item = first.item;
      first = first.next;
      size--;
      return item;
  }

  public Item removeLast() {
      if (isEmpty()) {
          throw new NoSuchElementException("Deque is empty");
      }

      Item item = last.item;
      last = last.prev;
      size--;
      return item;
  }