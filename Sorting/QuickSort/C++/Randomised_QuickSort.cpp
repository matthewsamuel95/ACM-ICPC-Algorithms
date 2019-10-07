#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
using std::vector;
using std::swap;

vector<int> partitioning3(vector<int> &a,int l,int r){
	int i=l,j=l,k=r;
	int pivot=a[l];
	while(j<=k){
		if(a[j]<pivot){
				swap(a[i],a[j]);
				i++;
				j++;
			}
		else if(a[j]>pivot){
				swap(a[j],a[k]);
				k--;
			}
		else{
				j++;
			}
		}
	vector<int>partition = {i,k};
	return partition;
}
void randomized_QuickSort(vector<int> &a,int l,int r){
	if(l>=r){
		return ;
	}
	int m=l + rand() % (r - l + 1);
	swap(a[l],a[m]);
	vector<int> partition=partitioning3(a,l,r);
	randomized_QuickSort(a,l,partition[0]-1);
	randomized_QuickSort(a,partition[1]+1,r);
}
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_QuickSort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}