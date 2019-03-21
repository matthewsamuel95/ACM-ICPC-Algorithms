import java.util.Arrays;
/**
 * The selection sort algorithm chooses the smallest element from the array and
 * puts it in the first position. Then chooses the second smallest element and
 * stores it in the second position, and so on until the array is sorted.
 */
public class SelectionSort1{
	public static void selectionSort(int[] array, int leftIndex, int rightIndex) {
		for(int i = leftIndex; i <= rightIndex;i++) {
			int less = i;
			for(int j = i+1; j<= rightIndex; j++) {
				if(array[less] > array[j]) {
					less = j;
				}
			}
			int aux= array[i];
			array[i] = array[less];
			array[less] = aux;
		}
	}

	 /**
	  * Main Method 
	  */
    public static void main(String[] args) {
		int[] array = new int[] {8,1,4,5,7,2,3};
		selectionSort(array,0,array.length-1);
		System.out.println(Arrays.toString(array));
    
	 
    }           
}
