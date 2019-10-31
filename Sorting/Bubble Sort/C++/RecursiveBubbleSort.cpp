#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
         int temp = arr[i];
         arr[i] = arr[i+1];
         arr[i+1] = temp;
      }
   }
   if (n - 1 > 1) {
      bubbleSort(arr, n - 1);
   }
}
int main() {
   int arr[] = { 5,4,2,1,3 };
   int n = 5;
   bubbleSort(arr, n);
   for (int i = 0; i < n; i++) {
      cout<< arr[i]<<"\t";
   }
   return 0;
}
