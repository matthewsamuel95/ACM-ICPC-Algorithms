import java.util.Arrays;

public class BubbleSort {
	/**
	 * The bubble sort algorithm iterates over the array multiple times, pushing big
	 * elements to the right by swapping adjacent elements, until the array is
	 * sorted.
	 */
	public static void bubbleSort(int[] array, int leftIndex, int rightIndex) {
		for (int i = leftIndex; i < rightIndex; i++) {
			for (int j = leftIndex; j < rightIndex; j++) {
				if (array[j] > array[j + 1]) {
					int aux = array[j];
					array[j] = array[j + 1];
					array[j + 1] = aux;
				}
			}
		}
	}
  /**
   * Main Method
   */
	public static void main(String[] args) {
		int[] array = { 8, 2, 3, 4, 1, 5, 7, 6 };
		bubbleSort(array, 0, array.length - 1);
		System.out.println(Arrays.toString(array));
	}
}
