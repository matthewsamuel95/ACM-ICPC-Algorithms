public class CountingSort {

    public static int[] countingSort(int[] a, int k) {

        int c[] = new int[k];
		for (int i = 0; i < a.length; i++)
			c[a[i]]++;
		for (int i = 1; i < k; i++)
			c[i] += c[i-1];
		int b[] = new int[a.length];
		for (int i = a.length-1; i >= 0; i--)
			b[--c[a[i]]] = a[i];
		return b;

	}

    public static void main(String[] args) {
        int array[] = {473, 78, 92, 5, 18, 7, 65, 89};
        int sortedArray[];
        System.out.println("Before: ");
        int n = array.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(array[i] + " ");
        }
        System.out.println();

        sortedArray = countingSort(array, 474);

        System.out.println("After: ");
        n = sortedArray.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(sortedArray[i] + " ");
        }
        System.out.println();
    }

}
