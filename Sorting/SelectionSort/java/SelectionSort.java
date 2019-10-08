import java.util.Arrays;

public class SelectionSort {

	public static void main(String[] args) {
		SelectionSort sl = new SelectionSort();
		int[] array = { 8, 4, 7, 1 ,5, 10, 1};
		sl.selectionSort(array);
        System.out.println(Arrays.toString(array));
    }

	public void selectionSort(int[] array) {
		for (int i = 0; i < array.length - 1; i++) {
			int less = i;
			for (int j = i + 1; j < array.length; j++) {
				if (array[less] > array[j]) {
					less = j;
				}
			}
			swap(array, i, less);
			
		}
	}

	public int[] swap(int[] array, int i, int j) {
		int aux = array[i];
		array[i] = array[j];
		array[j] = aux;
		return array;
	}
}