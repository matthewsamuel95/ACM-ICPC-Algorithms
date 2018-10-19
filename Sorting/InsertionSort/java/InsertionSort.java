public class InsertionSort {     
    public static int[] insertionSort(int[] input){
         
        int temp;
        for (int i = 1; i < input.length; i++) {
            for(int j = i ; j > 0 ; j--){
                if(input[j] < input[j-1]){
                    temp = input[j];
                    input[j] = input[j-1];
                    input[j-1] = temp;
                }
            }
        }
        return input;
    }
    
    	/* A utility function to print array of size n */
	    static void printSortedArray(int arr[])
	    {
		      int n = arr.length;
		      for (int i=0; i<n; ++i)
		      	System.out.print(arr[i]+" ");
		      System.out.println();
	    }
    
       public static void main(String a[]){
        int[] arr1 = {10,34,2,56,7,67,88,42};
        
        System.out.print("Before: ");
        printSortedArray(arr1);
        
        System.out.print("After: ");
        printSortedArray(insertionSort(arr1));
    }
}
