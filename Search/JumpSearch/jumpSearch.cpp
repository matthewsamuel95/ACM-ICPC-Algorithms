#include<bits/stdc++.h> //you can also use #include<iostream.h> but then also include math.h
using namespace std;
#define MAX 500
//function to perfrom jump search
int jumpSearch(int array[],int x,int n)
{
  //Finding block size to be jumped
  int st=sqrt(n);
  //Finding the block where the element is present
  int prev=0;
  while(array[min(st,n)-1]<x)
  {
    prev=st;
    st+=sqrt(n);
    if(prev>=n)
       return -1;
  }
  //Doing liner search to find the element
  while(array[prev]<x)
  {
    prev++;
    if(prev==min(st,n)) // if we reach the next block
      return -1;
  }
  //else if the element is found
  if(array[prev]==x)
  {
    return prev;
  }
  return -1;
}
int main()
{
  int arr[MAX];
  cout<<"Enter the number of array elements: ";
  int n,search;
  cin>>n;
  for(int i=0;i<n;i++)   //Taking input to array
    cin>>arr[i];
  cout<<"Enter the element to be searched: ";
  cin>>search;
  int index=jumpSearch(arr,search,n);
  //print the index where the element is located
  if(index==-1)
  cout<<"Element not found";
  else
  cout<<"The element is at index "<<index;

  return 0;

}
