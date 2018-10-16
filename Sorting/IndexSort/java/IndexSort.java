import java.util.Arrays;

public class IndexSort {
    public static void main(String[] args) {
        int unsortedInput[] = {12, 43, 92, 42, 18, 7, 65, 97};
        //print sorted array
        for (int i: indexSort(unsortedInput)){
            System.out.println(i);
        }
    }

    public static int[] indexSort(int input[]){
        //get max value of the array
        int max = Arrays.stream(input).max().getAsInt();
        int output[] = new int[max+1];
        for(int n: input){
            output[n] = n;
        }

        //removing null elements
        return Arrays.stream(output)
                .filter(i -> (i != 0))
                .toArray();
    }
}