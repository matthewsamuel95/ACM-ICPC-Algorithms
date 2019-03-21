#include <bits/stdc++.h>

using namespace std;

void PreProcess(int array[], int x){
    int i;
    for(i = 0; i < x; i++){
        array[i] = i;
    }
}
bool Find(int array[], int A, int B){
    if(array[A] == array[B]){
        return true;
    }
    else{
        return false;
    }
}
//Change all entries from array[A] to array[B].
void Union(int array[], int A, int B, int x){ // x is the size of my array
    int i;
    int temp = array[A];
    array[A] = array[B];
    for(i = 0; i < x; i++){
        if(array[i] == temp){
            array[i] = array[B];
        }
    }
}
int main(){
    int array[10]; // Array of integers. Each element represents a subset that contains only one element.
    PreProcess(array, 10);
    return 0;
}
