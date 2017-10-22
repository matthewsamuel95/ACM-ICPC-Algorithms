    public class BubbleSort {  
        static void bubbleSort(int[] arr) {  
            int n = arr.length;  
            int temp = 0;  
             for(int i=0; i < n; i++){  
                     for(int j=1; j < (n-i); j++){  
                              if(arr[j-1] > arr[j]){  
                                     //swap elements  
                                     temp = arr[j-1];  
                                     arr[j-1] = arr[j];  
                                     arr[j] = temp;  
                             }  
                              
                     }  
             }  
      
        }  
        
        	/* A utility function to print array of size n */
	    public static void printSortedArray(int arr[])
	    {
	      	int n = arr.length;
		      for (int i=0; i<n; ++i)
		      	  System.out.print(arr[i]+" ");
		      System.out.println();
	    }
      
      public static void main(String[] args) {  
                    int arr[] ={4,65,75,2,78,90,170};  
                     
                    System.out.println("Before: ");  
                    printSortedArray(arr);
                      
                    bubbleSort(arr);//sorting array elements using bubble sort  
                     
                    System.out.println("After: ");  
                    printSortedArray(arr);
       
            }  
    }  
