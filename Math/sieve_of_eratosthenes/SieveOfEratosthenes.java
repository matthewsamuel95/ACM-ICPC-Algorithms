import java.util.Arrays;
import java.util.Scanner;

public class SieveOfEratosthenes
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		int n = input.nextInt();
		System.out.println("The prime numbers up to " + n + " are:");
		sieve(n);
	}

	public static void sieve(int n)
	{
		boolean primes[] = new boolean[n + 1];

		Arrays.fill(primes, true);

		primes[0] = false;
		primes[1] = false;

		for (int p = 2; p * p <= n; p += (p == 2 ? 1 : 2))
		{
			if (!primes[p])
			{
				continue;
			}

			for (int multiplier = p; multiplier * p <= n; multiplier++)
			{
				primes[p * multiplier] = false;
			}
		}
		for (int i = 2; i <= n; i++)
		{
			if (primes[i])
			{
				System.out.println(i);
			}
		}
	}
}
