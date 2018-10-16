/*
Minimum number of Coins
----------------------------------------------------------------------------------
Given a value N, if we want to make change for N Rs,
and we have infinite supply of each of the denominations in Indian currency,
i.e., we have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes,
Find the minimum number of coins and/or notes needed to make the change.

Input:

The first line of input contains an integer T denoting the number of test cases.
Each test case consist of an Integer value N denoting the amount to get change for.


Output:

Print all the possible denominations needed to make the change in a separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 2000


Example:

Input
1
43
Output
20 20 2 1
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		int[] array={1, 2, 5, 10, 20, 50, 100, 500, 1000};
		for(int i=0;i<t;i++){
		    int n=sc.nextInt();
		    MinimumNumberOfCoins(array,n);
		    System.out.println();
		}
	}
	private static void MinimumNumberOfCoins(int[] array,int n){
	    int length=array.length;
	    for(int i=length-1;i>=0;i--){
	        if(array[i]<=n){
	            int numOfCoins=n/array[i];
	            for(int j=0;j<numOfCoins;j++)System.out.print(array[i]+" ");
	            n%=array[i];
	        }
	    }
	}
}