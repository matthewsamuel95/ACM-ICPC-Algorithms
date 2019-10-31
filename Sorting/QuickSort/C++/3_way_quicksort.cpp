#include<bits/stdc++.h>
using namespace std;
void swap(int* arr,int a,int b){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
void qs(int* arr,int start,int end){
	if(start>=end)
		return;
	int pivot=arr[start];
	int first=start,last=end,mid=start+1;
	while(mid<=last){
		if(arr[mid]<pivot)	swap(arr,first++,mid++);
		else if(arr[mid]>pivot)	swap(arr,mid,last--);
		else	mid++;
	}
	qs(arr,start,first-1);
	qs(arr,last+1,end);
}
