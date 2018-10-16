#include <stdio.h>
#include <stdlib.h>
long int ncr(int n,int r,long int prev){
	long int a = (n-r+1)*prev/r;
	return a;
}
int* getRow(int A) {
	int i,*result = (int *) malloc((A+1) * sizeof(int));
	result[0]=1;
	for(i=1;i<=A;i++)    
		result[i]=ncr(A,i,result[i-1]);
	return result;         
}
int main(){
	int n,*res,i;
	scanf("%d",&n);
	res=getRow(n);
	for(i=0;i<n+1;i++)
		printf("%d ",res[i]);
	printf("\n");
	return 0;
}