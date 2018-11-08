#include <bits/stdc++.h>
using namespace std;

#define pb push_back

void merge(vector<int> &a, int l, int m, int h){
	int n1 = m-l+1;
	int n2 = h-m;
	vector<int> t1,t2;
	t1.resize(n1);
	t2.resize(n2);
	for(int i=0;i<n1;i++)t1[i]=a[l+i];
	for(int i=0;i<n2;i++)t2[i]=a[m+1+i];

	int i(0),j(0),k(l);
	while(i<n1 && j<n2){
		if(t1[i]<=t2[j])a[k++]=t1[i++];
		else a[k++]=t2[j++];
	}
	while(i<n1){
		a[k++]=t1[i++];
	}
	while(j<n2){
		a[k++]=t2[j++];
	}
}

void mergeSort(vector<int> &a, int l, int h){	
	if(l<h){
		int m = l+(h-l)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,h);
		merge(a,l,m,h);
	}

}

void print(vector<int> &a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;
}
int main(){
	srand(time(0));
	vector<int> a;
	int n=10;
	for(int i=0;i<n;i++){
		a.pb(rand()%1001);
	}
	print(a,n);
	mergeSort(a,0,n-1);
	print(a,n);

}
