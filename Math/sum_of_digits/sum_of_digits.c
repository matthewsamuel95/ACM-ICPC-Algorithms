#include <stdio.h>

int sum_of_digits(int n){
	int sum = 0, i, tmp;
	
	for(i = 1; i <= n; i++){
		tmp = i;
		while(tmp){
			sum += tmp%10;
			tmp = tmp/10;
		}
	}
	
	return sum;
}

int main(){
	
	printf("%d\n", sum_of_digits(5));   //output is 15
	printf("%d\n", sum_of_digits(12));  //output is 51
	printf("%d\n", sum_of_digits(328)); //output is 3241
	printf("%d\n", sum_of_digits(32)); //output is 177
	return 0;
}
