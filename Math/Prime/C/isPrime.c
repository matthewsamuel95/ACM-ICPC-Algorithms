#include <stdio.h>
#include <math.h>

void isPrime(int x){
	if (x == 0 || x == 1) {
		printf("This number is not prime !\n");
		return;
	}
	int flag = 1;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) flag = 0;
	if (flag) printf("This number is prime !\n");
	else printf("This number is not prime !\n");
}

int main() {
	int x;
	scanf("%d", &x);
	isPrime(x);
	return 0;
}
