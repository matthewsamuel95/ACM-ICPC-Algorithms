package dsa;


import java.util.*;

public class Driver {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int value;
		int c = 1, a;
		Node l = new Node();
		
		while (c == 1) {
			a = 1;
		System.out.println(" ============================");
		System.out.println("|          Choose            |");
		System.out.println(" ============================");
		System.out.println("| 1 |Insert at first         |");
		System.out.println("| 2 |Insert at last          |");
		System.out.println("| 3 |Insert at Position      |");
		System.out.println("| 4 |Delete first element    |");
		System.out.println("| 5 |Delete Last element     |");
		System.out.println("| 6 |Delete at position      |");
		System.out.println("| 7 |Check whether empty List|");
		System.out.println("| 8 |Print List              |");
		System.out.println("==============================");
	
			System.out.println("select an option from table");
			int ch = sc.nextInt();
			switch (ch) {
			case 1:
				while (a == 1) {
					System.out.println("*Enter element to be inserted at  first*");
					value = sc.nextInt();
					l.insertAtFront(value);
					System.out.println("enter 1 to continue this function:");
					a = sc.nextInt();
				}
				break;
			case 2:
				while (a == 1) {
					System.out.println("*Enter element to be inserted at Last*");
					value = sc.nextInt();
					l.insertAtLast(value);
					System.out.println("enter 1 to continue this function:");
					a = sc.nextInt();
				}
				break;
			case 3:
				while (a == 1) {
					System.out.println("Enter the position: ");
					int position = sc.nextInt();
					System.out.println("*Enter element to be inserted at position*");
					value = sc.nextInt();
					l.InsertAtPos(position, value);
					System.out.println("enter 1 to continue this function:");
					a = sc.nextInt();
				}
				break;
			case 4:
				l.delAtFirst();
				System.out.println("Node deleted!");
				break;
			case 5:
				l.delAtLast();
				System.out.println("Node deleted!");
				break;
			case 6:
				System.out.println("Enter the position:");
				value = sc.nextInt();
				l.delAtPos(value);
				System.out.println("Node deleted!");
				break;
			case 7:
				l.isEmpty();
				break;
			case 8:
				l.printList();
				break;
			
			}
			System.out.println("enter 1 to go back to table , 0 to Quit:");
			c = sc.nextInt();
		}
	}

}