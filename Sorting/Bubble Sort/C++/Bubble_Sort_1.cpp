#include <iostream>
using namespace std;

void bubbleSort(int array[], int size, int order){

  if(order == 1){
    for(int i=0; i < size-1; i++){
      int flag = 0;

      for(int j=0; j<size-1-i; j++){
        if(array[j] > array[j+1]){
          swap(array[j+1], array[j]);
          flag = 1;
        }
      }
      if(flag == 0){
        break;
      }
    }
  }

  else if(order == 2){
    for(int i=0; i < size-1; i++){
      int flag = 0;

      for(int j=0; j<size-1-i; j++){
        if(array[j] < array[j+1]){
          swap(array[j+1], array[j]);
          flag = 1;
        }
      }
      if(flag == 0){
        break;
      }
    }
  }

}

int main() {
  int size;
  int order;

  cout << "Enter the size of the array:" << endl;
	cin >> size;

	int array[size];

	cout << "Enter the elements of the array:" << endl;
	for(int i = 0; i < size; i++){
	  cin >> array[i];
  }

  cout << "What type of ordering do you want: \n 1 - Ascending \n 2 - Descending" << endl;
  cin >> order;

	bubbleSort(array, size, order);

	cout << "The sorted array is:" <<endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
  }

  return 0;
}
