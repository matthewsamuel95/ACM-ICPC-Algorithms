import java.util.Scanner;
public class SetKthBit{ 
      
// function to set the kth bit 
static int setKthBit(int n, int k) 
{ 
    // kth bit of n is being set by this operation 
    return ((1 << k) | n); 
} 
  
// Driver code 
public static void main(String arg[]) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int k = in.nextInt();
    System.out.print("Kth bit set number = " +  
                             setKthBit(n, k)); 
  } 
} 
