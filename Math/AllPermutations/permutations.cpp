#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
	return;
}

void permute(int *array,int i,int length) { 
  if (length == i){
     	for(int i=0;i<length;i++)
		cout << array[i] <<" ";
		cout << "\n";
     return;
  }
  int j = i;
  for (j = i; j < length; j++) { 
     swap(array+i,array+j);
     permute(array,i+1,length);
     swap(array+i,array+j);
  }
  return;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	int *p;
	p=a;
	for(int i=0;i<n;i++)
		cin >> a[i];
	permute(p,0,n);
}
