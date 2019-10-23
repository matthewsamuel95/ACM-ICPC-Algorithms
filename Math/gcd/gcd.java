import java.util.*;
import java.io.*;

public class gcd {

	public static int gcd(int a, int b) {
		if(b==0)
			return a;
		if(a==0)
			return b;
		return gcd(b,a%b);
	}

	public static void main(String ars[]) {
		int num1,num2,res;
		Scanner inp = new Scanner(System.in);
		System.out.println("Enter the first number: ");
		num1 = inp.nextInt();
		System.out.println("Enter the second number: ");
		num2 = inp.nextInt();
		res = gcd(num1,num2);
		System.out.println("The GCD of "+num1+" and "+num2+" is "+res);
	}
}
