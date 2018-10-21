import java.util.Arrays;

public class RecursiveBubbleSort {
	/**
	 * The recursive bubble sort algorithm iterates over the array multiple times,
	 * pushing big elements to the right by swapping adjacent elements,and then
	 * calling recursiveBubbleSort to sort the array between left to right -1 until
	 * the array is sorted.
	 */
	public static void recursiveBubbleSort(int[] array, int leftIndex, int rightIndex) {
		for (int j = leftIndex; j < rightIndex; j++) {
			if (array[j] > array[j + 1]) {
				int aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
			}
			recursiveBubbleSort(array, leftIndex, rightIndex - 1);
		}
	}

	public static void main(String[] args) {
		int[] array = { 8, 2, 3, 4, 1, 5, 7, 6 };
		recursiveBubbleSort(array, 0, array.length - 1);
		System.out.println(Arrays.toString(array));
	}
}
