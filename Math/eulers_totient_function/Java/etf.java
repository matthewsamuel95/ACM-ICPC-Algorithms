// A simple java program to calculate 
// Euler's Totient Function 
import java.io.*; 
  
class GFG { 
  
    // Function to return GCD of a and b 
    static int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    } 
  
    // A simple method to evaluate 
    // Euler Totient Function 
    static int phi(int n) 
    { 
        int result = 1; 
        for (int i = 2; i < n; i++) 
            if (gcd(i, n) == 1) 
                result++; 
        return result; 
    } 
  
    // Driver code 
    public static void main(String[] args) 
    { 
        int n; 
  
        for (n = 1; n <= 10; n++) 
            System.out.println("phi(" + n + ") = " + phi(n)); 
    } 
} 
