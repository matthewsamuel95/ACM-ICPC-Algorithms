public class Stack<T> {
	
	private T[] array;
	private int top;
	
	public Stack(int size) {
		array = (T[]) new Object[size];
		top = -1;
	}
	
	public boolean isEmpty() {
		return this.top == -1;
	}
	
	public boolean isFull() {
		return this.top == (array.length - 1);
	}
	
	public void push(T element) throws RuntimeException {
		if (isFull())
			throw new RuntimeException();
		
		this.top++;
		this.array[top] = element;
	}
	
	public T pop(T element) throws RuntimeException {
		if (isEmpty())
			throw new RuntimeException();
		
		T removedElement = array[top];
		this.top--;
		
		return removedElement;
	}
	
	public T top() {
		if (isEmpty())
			return null;
		return this.top;
	}



}
