#include <bits/stdc++.h>
using namespace std;

#define pb push_back

void print(vector<int> &a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;
}

int partition(vector<int> &a, int l, int h){
	int pivot = a[h];
	int i = l-1;
	for(int j=l;j<h;j++){
		if(a[j]<=pivot)swap(a[++i],a[j]);
	}
	swap(a[++i],a[h]);
	return i;
}

void quickSort(vector<int> &a, int l, int h){
	if(l<h){
		int pivot = partition(a,l,h);
		quickSort(a, l, pivot-1);
		quickSort(a, pivot+1, h);
	}
}

int main(){
	srand(time(0));
	vector<int> a;
	int n=10;
	for(int i=0;i<n;i++){
		a.pb(rand()%1001);
	}
	print(a,n);
	quickSort(a,0,n-1);
	print(a,n);

}
