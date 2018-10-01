/*Simple Java code to calcutate Log2n and return the integer value*/
public class calcLog{
    public static void main(String args[]){
        System.out.print(calcLog2n(129));
    }
    
    private static int calcLog2n(int n){
        return (n>1)?(1+calcLog2n(n/2)):0; //recursive call to calculate log2n
    }
}