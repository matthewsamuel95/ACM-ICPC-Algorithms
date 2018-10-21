# Fibonacci Sequence

In mathematics, the Fibonacci numbers are the numbers in the following integer sequence, called the Fibonacci sequence, and characterized by the fact that every number after the first two is the sum of the two preceding ones.

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/d9941f4184ea7677a056402b98d8b741af937f80)

Fibonacci sequence is entirely described by this property:

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/0fff1a1716fcc169546079870357f92757ade5fa)

##### Fore More Information: [Wikipedia - Fibonacci Numbers](https://en.wikipedia.org/wiki/Fibonacci_number)

### C-Implementation of Fibonacci Prgram:

 Recursive Implementation:
 
 ```c
 
 #include <stdio.h>
 int Fib(int n) 
{ 
        // Base condition to break recursion
        if (n <= 1) 
                return n;
        
        // Recursive call of function Fib for
        // 'n-1'th and 'n-2'th element of sequence
        return Fib(n-1) + Fib(n-2); 
}
  
int main() 
{ 
        // Fibonacci sequence size
        int n = 10;
        
        // Print the first n elements of the sequence
        printf("%d", Fib(n-1)); 
        
    return 0; 
}

 ```
 
 Dynamic Programing Implementation:
 
 ```c
 
 #include <stdio.h>
 int main()
{
        // Fibonacci sequence size
        const int n = 10;
        
        // Array to store the Fibonacci series
	int Fib[105];
        // Initializing the first two elements of series
	Fib[0] = 0; Fib[1] = 1;
        
	for(int i = 2; i < n; i++)
                // Calculate the the 'i'th element by 
                // adding 'i-1'th and 'i-2'th elements
                Fib[i] = Fib[i-1] + Fib[i-2];
        
        // Print the first n elements of the Fibonacci sequence
	for(int i = 0; i < n; i++)
        {
                printf("%d : %d", i, Fib[i]);
                printf("\n");
        }
	
    return 0;
}

 ```
