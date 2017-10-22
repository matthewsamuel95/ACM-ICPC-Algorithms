public class RadixSort {

    protected static int d = 8;
    protected static int w = 32;

    public static int[] radixSort(int[] a) {
		int[] b = null;
		for (int p = 0; p < w/d; p++) {
			int c[] = new int[1<<d];
			b = new int[a.length];
			for (int i = 0; i < a.length; i++)
				c[(a[i] >> d*p)&((1<<d)-1)]++;
			for (int i = 1; i < 1<<d; i++)
				c[i] += c[i-1];
			for (int i = a.length-1; i >= 0; i--)
				b[--c[(a[i] >> d*p)&((1<<d)-1)]] = a[i];
			a = b;
		}
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

        sortedArray = radixSort(array);

        System.out.println("After: ");
        n = sortedArray.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(sortedArray[i] + " ");
        }
        System.out.println();
    }
}
