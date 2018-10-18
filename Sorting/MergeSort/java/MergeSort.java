
public class MergerSort {

    public static void mergeSort(Comparable[] array) {
        Comparable[] temp = new Comparable[array.length];
        mergeSort(array, temp, 0, array.length - 1);
    }

    private static void merge(Comparable[] a, Comparable[] temp, int left, int right, int rightLast) {
        int leftLast = right - 1;
        int k = left;
        int num = rightLast - left + 1;

        while (left <= leftLast && right <= rightLast) {
            if (a[left].compareTo(a[right]) <= 0) {
                temp[k++] = a[left++];
            } else {
                temp[k++] = a[right++];
            }
        }

        while (left <= leftLast) // The rest of the first half will be copied
        {
            temp[k++] = a[left++];
        }

        while (right <= rightLast) // The rest of the right half will be copied
        {
            temp[k++] = a[right++];
        }

        // The temp array will copied back
        for (int i = 0; i < num; i++, rightLast--) {
            a[rightLast] = temp[rightLast];
        }
    }

    private static void mergeSort(Comparable[] arr, Comparable[] tmp, int left, int right) {
        if (left < right) {
            int center = (left + right) / 2;
            mergeSort(arr, tmp, left, center);
            mergeSort(arr, tmp, center + 1, right);
            merge(arr, tmp, left, center + 1, right);
        }
    }

    public static void printArray(Integer arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Integer[] arr = {473, 78, 92, 5, 18, 7, 65, 89};
        System.out.println("Before: ");  
        printArray(arr);
        
        mergeSort(arr);
        
        System.out.println("After: ");  
        printArray(arr);
    }
}
