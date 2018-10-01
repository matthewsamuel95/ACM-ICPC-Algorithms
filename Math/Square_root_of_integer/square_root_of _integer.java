class GFG { 
      
    
    static int floorSqrt(int x) 
    { 
        // Base cases 
        if (x == 0 || x == 1) 
            return x; 
  
        // Staring from 1, try all numbers until 
        // i*i is greater than or equal to x. 
        int i = 1, result = 1; 
          
        while (result <= x) { 
            i++; 
            result = i * i; 
        } 
        return i - 1; 
    } 
  
    // Driver program 
    public static void main(String[] args) 
    { 
        int x = 11; 
        System.out.print(floorSqrt(x)); 
    } 
} 