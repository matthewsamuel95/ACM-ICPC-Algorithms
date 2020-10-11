// Iterative C# program to 
// compute modular power 
class GFG 
{ 

/* Iterative Function to calculate 
(x^y)%p in O(log y) */
static int power(int x, int y, int p) 
{ 
	// Initialize result 
	int res = 1;	 
	
	// Update x if it is more 
	// than or equal to p 
	x = x % p; 
	
	if (x == 0) 
	return 0; 

	while (y > 0) 
	{ 
		// If y is odd, multiply 
		// x with result 
		if ((y & 1) == 1) 
			res = (res * x) % p; 

		// y must be even now 
		// y = y / 2 
		y = y >> 1; 
		x = (x * x) % p; 
	} 
	return res; 
} 

// Driver Code 
public static void Main() 
{ 
	int x = 2; 
	int y = 5; 
	int p = 13; 
	System.Console.WriteLine("Power is " + 
							power(x, y, p)); 
} 
} 

// This code is contributed by mits 
