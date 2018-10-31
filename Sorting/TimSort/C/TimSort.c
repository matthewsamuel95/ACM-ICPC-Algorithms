#include <stdio.h>
#include <stdlib.h>

const int RUN = 32; 

int MIN(int a ,int b) {
    return (a > b) ? b : a;
}
void insertionSort(int arr[], int left, int right) 
{ 
	for (int i = left + 1; i <= right; i++) 
	{ 
		int temp = arr[i]; 
		int j = i - 1; 
		while (arr[j] > temp && j >= left) 
		{ 
			arr[j+1] = arr[j]; 
			j--; 
		} 
		arr[j+1] = temp; 
	} 
} 

void merge(int arr[], int l, int m, int r) 
{ 
	int len1 = m - l + 1, len2 = r - m; 
	int left[len1], right[len2]; 
	for (int i = 0; i < len1; i++) 
		left[i] = arr[l + i]; 
	for (int i = 0; i < len2; i++) 
		right[i] = arr[m + 1 + i]; 

	int i = 0; 
	int j = 0; 
	int k = l; 
	while (i < len1 && j < len2) 
	{ 
		if (left[i] <= right[j]) 
		{ 
			arr[k] = left[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = right[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < len1) 
	{ 
		arr[k] = left[i]; 
		k++; 
		i++; 
	} 

	while (j < len2) 
	{ 
		arr[k] = right[j]; 
		k++; 
		j++; 
	} 
} 

void timSort(int arr[], int n) 
{  
	for (int i = 0; i < n; i+=RUN) 
		insertionSort(arr, i, MIN((i+31), (n-1))); 
	for (int size = RUN; size < n; size = 2*size) 
	{ 
		for (int left = 0; left < n; left += 2*size) 
		{ 
			int mid = left + size - 1; 
			int right = MIN((left + 2*size - 1), (n-1)); 
			merge(arr, left, mid, right); 
		} 
	} 
} 
void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int arr[] = {5, 21, 7, 23, 19}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Given Array is\n"); 
	printArray(arr, n); 

	timSort(arr, n); 

	printf("After Sorting Array is\n"); 
	printArray(arr, n); 
	return 0; 
} 
