/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner (System.in);
		int n=sc.nextInt();
		int ri=0,r=0,c=n;
		while(n>0)
		{
			r=n%10;
			ri=ri*10+r;
			n=n/10;
		}
		if(c==ri){
		 System.out.println("Palindrome  "+c);
			   	}
			   	else
			   	{
			   		
		 System.out.println("Not Palindrome "+c);
			   	}
}
}
