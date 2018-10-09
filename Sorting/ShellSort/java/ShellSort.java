public class ShellSort{

    public static int[] shellSort(int arr[]){
        int temp;
        int n = arr.length;
        // Gap of size n/2 initially
        for(int i = n/2; i>0; i=i/2){
            for(int j = i; j<n; j++){
                for(int k=j-i;k>=0;k=k-i){
                    // break loop if is higher, if not switch
                    if(arr[k+i]>=arr[k]){
                        break;
                    }else{
                        temp = arr[k];
                        arr[k] = arr[k+i];
                        arr[k+i] = temp;
                    }
                }
            }
        }
        return arr;
    }


    public static void main(String[] args) {
        int array[] = {473, 78, 92, 5, 18, 7, 65, 89, 7};
        int sortedArray[];
        System.out.println("Before: ");
        int n = array.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(array[i] + " ");
        }
        System.out.println();

        // shell sort
        sortedArray = shellSort(array);        
        System.out.println("After: ");
        n = sortedArray.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(sortedArray[i] + " ");
        }
        System.out.println();
    }
}