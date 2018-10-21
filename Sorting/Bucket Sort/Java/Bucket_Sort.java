import java.util.*;
 //O(nlogn)
public class BucketSort{

   public static void bucketSort(int[] a) {
	  int maxVal=a[0];
	  for(int i=0;i<a.length;i++){
		  if(a[i]>maxVal){
			  maxVal=a[i];
		  }
	  }
      int [] bucket=new int[maxVal+1];
 
	  System.out.println("\n");
      for (int i=0; i<a.length; i++) {
         bucket[a[i]]++;
		 //System.out.print(bucket[a[i]-1]);
      }
 
      int outPos=0;
      for (int i=0; i<bucket.length; i++) {
		if(bucket[i]!=0){
			for (int j=0; j<bucket[i]; j++) {
				a[outPos++]=i;
				System.out.println(bucket[i]);
			}
		}
      }
   }
   
 
 
   public static void main(String[] args) {
      int [] data= {10,23,53,22,1,1,100,32,58,34,42,64}; 
 
      System.out.println("Before: " + Arrays.toString(data));
      bucketSort(data);
      System.out.println("After:  " + Arrays.toString(data));
   }
}