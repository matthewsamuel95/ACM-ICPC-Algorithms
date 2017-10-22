//Search algorithm for sorted list, with complexity of the order O(log(n)).
#include <iostream>
#include <vector>

using namespace std;

int fibsearch(vector<int> arr,int x){
  //indicates first two fibonacci nummbers
  int fib2 = 0,fib1 = 1;
  int fib = fib1 + fib2;

  int len = arr.size();
  //to calculate smallest fibonacci no greater than or equal to len
  while(fib < len){
    fib2 = fib1;
    fib1 = fib;
    fib = fib1 + fib2;
  }
  int leftout = -1; //the leftout list for the array
  while(fib > 1){
    //to get a valid index
    int index = min(leftout + fib2 , len - 1);

    if(arr[index] > x){
      fib = fib2;
      fib1 -= fib2;
      fib2 = fib - fib1;
    }
    else if(arr[index]<x){
      fib = fib1;
      fib1 = fib2;
      fib2 = fib - fib1;
      leftout = index;
    }
    else{
      return index;
    }
  }

  if(fib1 && arr[leftout + 1] == x){
    return leftout+1;
  }
  else{
    return -1;
  }
}
int main(){
  vector<int> arr;
  int n;//no of elements
  cin>>n;
  for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    arr.push_back(temp);
  }
  int search_no;//element to be searched
  cin>>search_no;
  int ans = fibsearch(arr,search_no);
  if(ans!=-1){
    cout<<"Given element found at index "<<ans<<endl;
  }
  else{
    cout<<"Given element is not found"<<endl;
  }
  return 0;
}
