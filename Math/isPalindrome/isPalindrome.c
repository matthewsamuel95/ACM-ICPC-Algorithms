#include <stdio.h>

int reverse(int x){
	int reverse = 0;
	while (x){
		reverse = reverse * 10 + (x % 10);
		x /= 10;
	}
	return reverse;
}

void isPalindrome(int x){
	if (x == reverse(x)) printf("This number is a Palindrome !\n");
	else printf("This number is not a Palindrome !\n");
}

int main(){
	int x;
	scanf("%d", &x);
	isPalindrome(x);
	return 0;
}
