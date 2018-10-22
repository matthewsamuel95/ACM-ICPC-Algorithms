package Jun5_ArrayOps_lec5;

import java.util.Scanner;

public class Binary_search {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		int[] arr = TakeInput();
		Display(arr);
		System.out.println();
		System.out.println("enter data");
		int d = scn.nextInt();
		int index = Binary_Search(arr, d);
		System.out.println(index);

	}

	public static int Binary_Search(int[] A, int data) {
		int left = 0, right = A.length - 1;

		while (left <= right) {
			int mid = (left + (right - left)) / 2;
			if (data > A[mid]) {
				left = mid + 1;
			} else if (data < A[mid]) {
				right = mid - 1;
			} else {
				return mid;
			}
		}
		return -1;
	}

	public static int[] TakeInput() {
		System.out.println("enter num of elements");
		int n = scn.nextInt();
		int[] A = new int[n];
		for (int i = 0; i < A.length; i++) {
			System.out.println("enter " + i + "th element");
			A[i] = scn.nextInt();
		}
		return A;
	}

	public static void Display(int[] A) {
		for (int i = 0; i < A.length; i++) {
			System.out.print(A[i] + "	");
		}
	}
}
