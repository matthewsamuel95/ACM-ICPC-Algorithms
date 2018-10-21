//this sort is O(n) but it cannot handle when the max value of an element is too high
//also this sort is unstable
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector <int> v;
void index_sort(int l,int m){
    int arr[m];
    memset(arr,0,sizeof(arr));
    for (int x=0;x<l;x++){
        ++arr[v[x]];
    }
    v.clear();
    for (int x=0;x<m;x++){
        for (int y=0;y<arr[x];y++){
            v.push_back(x);
        }
    }
}
void print(){
    for (int x=0;x<v.size();x++){
        printf("%d ",v[x]);
    }
    printf("\n");
}
int main(){
    v.push_back(10);
    v.push_back(13);
    v.push_back(12);
    v.push_back(14);
    v.push_back(11);
    v.push_back(23);
    v.push_back(11);
    v.push_back(12);
    printf("original vector: ");
    print();
    index_sort(v.size(),100); //length of vector to sort, max element of vector +1
    printf("sorted vector: ");
    print();
    return 0;
}
