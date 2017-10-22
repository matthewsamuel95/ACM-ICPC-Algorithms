import java.util.*;
 
public class BucketSort{
 
   public static void sort(int[] a, int maxVal) {
      int [] bucketArray=new int[maxVal+1];
 
      for (int i=0; i<bucketArray.length; i++) {
         bucketArray[i]=0;
      }
 
      for (int i=0; i<a.length; i++) {
         bucketArray[a[i]]++;
      }
 
      int outPos=0;
      for (int i=0; i<bucketArray.length; i++) {
         for (int j=0; j<bucketArray[i]; j++) {
            a[outPos++]=i;
         }
      }
   }
 
 	/* A utility function to print array of size n */
	static void printSortedArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
  
   public static void main(String[] args) {
      int maxVal=52;
      int [] data= {15,13,0,21,43,11,10,52,2,3,17,4}; 
 
 
      System.out.println("Before: ");
      printSortedArray(data);
      sort(data,maxVal);
      System.out.println("After:  ");
      printSortedArray(data);
   }
}
