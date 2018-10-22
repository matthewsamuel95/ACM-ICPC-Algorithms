#include <stdio.h>

int binary_search(int A[], int k, int n){
	int i=0, r=n-1, m;
	while(i<=r){
		m = floor((i+r)/2);
		if(k==A[m]){
			return m;
		}
		else if(k<A[m]){
			r = m-1;
		}
		else{
			i = m+1;
		}
	}
	return -1; 
}

void display_search(int A[], int A_length) {
  for(int i = 0; i<A_length; i++) {
    printf("%d %s",A[i]," ");
  }
  printf("\n");
}

int main(){
	int vet[1000000], n , k, k_cases;
	scanf("%d %d", &n, &k_cases);
	int i;    
	for(i=0;i<n;i++){
		scanf("%d", &vet[i]);
	}
  display_search(vet,n);
	while(k_cases--){
		scanf("%d", &k);
		k = binary_search(vet, k, n);
		while(vet[k]==vet[k-1]){
      display_search(vet,k);
			k--;
		}
		printf("%d\n",k);
		
	}	
	return 0;
}
