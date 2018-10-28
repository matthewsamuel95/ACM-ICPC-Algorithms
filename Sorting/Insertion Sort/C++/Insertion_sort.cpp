#include<iostream>
using namespace std;

void insertion_sort(int vet[],int n){
	int i, j, v;
	for(i=0;i<n;i++){
		v = vet[i];
		j = i-1;
		while(j>=0 && vet[j]>v){
			vet[j+1] = vet[j];
			j = j-1;
		}
		vet[j+1] = v;
	}
}
int main() {
	ios::sync_with_stdio(0);
    	cin.tie(0);
    
	int vet[100000], vetn=0;
	cin >> vetn;
	int i;
	for(i=0;i<vetn;i++){
		cin >> vet[i];
	}
	
	insertion_sort(vet, vetn);
	
	for(i=0;i<vetn;i++){
		cout << vet[i] << " ";
	}
	return 0;
}
