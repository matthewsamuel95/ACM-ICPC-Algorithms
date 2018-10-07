import java.util.Scanner;

public class Power {
    public static int power(int x, int y, int p) 
    { 
        int ans = 1;      
        x = x % p;  
      
        while (y > 0) 
        { 
            if((y & 1)==1) 
                ans = (ans * x) % p;
            y = y >> 1;  
            x = (x * x) % p;  
        } 
        return ans; 
    } 


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt(); 
        int y = sc.nextInt();
        int m = sc.nextInt();
        double ans = fast_expo(x, y, m);

        System.out.println(ans);
    }
}