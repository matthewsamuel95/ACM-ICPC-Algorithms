// Longest palindromic substring
// Manacher's algorithm

import java.util.Arrays;

class LPS{

    static void printSubStr(String str, int low, int high) { 
        System.out.println(str.substring(low, high + 1)); 
    } 

    public static void main(String[] args) { 
        String str = "abcdcbaf"; 
        System.out.println("Length is: " +  
                                 longestPalSubstr(str)); 
    } 

    // input string
    static int longestPalSubstr(String str){

        // Get the length
        int n = str.length();

        // make a table of length * length
        boolean table[][] = new boolean[n][n];

        // single letter is always palindrome 
        // Lol
        // make max = 1
        int maxLength = 1;
        
        // and fill the diagonals as 1 as true
        for (int i = 0; i < n; ++i) 
            table[i][i] = true;

        
        // for strings with length 2
        int start = 0;

        // go ot n-1
        for(int i = 0; i< n-1; i++){
            
            // this and immidiate next
            if(str.charAt(i) == str.charAt(i+1)){
                // if matched make it true
                // i and i+1
                table[i][i+1] = true;
                
                // this is palindrome and hence update the start and maxlength
                start = i;
                maxLength = 2;
            }
        }


        // Now for 3 and more
        // we will use 1 and 2 data from table
        for(int k = 3; k <=  n; k++){
            for(int i = 0; i < n-k+1; i++){
                int j = i + k - 1;
                if(table[i+1][j-1] && str.charAt(i) == str.charAt(j)){
                    table[i][j] = true;

                    if(k > maxLength){
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }

        System.out.print("Longest palindrome substring is; "); 
        printSubStr(str, start, start + maxLength - 1); 
          
        return maxLength; // return length of LPS 
        
    }

}