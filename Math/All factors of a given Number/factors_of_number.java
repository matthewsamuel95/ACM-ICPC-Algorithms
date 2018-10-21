import java.util.Scanner;

public class sample_one {

    public static void main(String args[]) {
    
        // Java program to find all factors of a number
    
        Scanner scan = new Scanner(System.in);

        int num;
        int counter;
        
        // Takes user input
        
        System.out.print("Enter a number: ");
        num = scan.nextInt();
        
        // for loop which sees the counter increase by 1 after every division
        
        for (counter=1; counter<=num;)
        {
            // if remainder = 0; then number is a factor
            
            if (num%counter==0)
            {
                // prints number if it is a factor
                System.out.println(counter + " is a factor.");
            }

            counter = counter + 1;
        }
    }
}
