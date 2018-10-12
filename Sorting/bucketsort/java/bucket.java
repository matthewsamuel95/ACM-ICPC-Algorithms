public class bucket{

    public static void sort(int[] a, int maxVal) {
        int [] bucket=new int[maxVal+1];

        for (int i=0; i<bucket.length; i++) {
          bucket[i]=0;
        }

        for (int i=0; i<a.length; i++) {
          bucket[a[i]]++;
        }

        int outPos=0;
        for (int i=0; i<bucket.length; i++) {
          for (int j=0; j<bucket[i]; j++) {
            a[outPos++]=i;
          }
        }
    }

    public static int getMaxValue(int[] arr){
        int maxVal = arr[0];
        for(int i=1;i < arr.length;i++){
          if(arr[i] > maxVal){
            maxVal = arr[i];
          }
        }
        return maxVal;
    }

    public static void main(String[] args){
        int[] array = {473, 78, 92, 5, 18, 7, 65, 89};
        sort(array, getMaxValue(array));
        System.out.println("Sorted array:  " + Arrays.toString(data));
    }
}
