#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
 
void bucketSort(float a[], int n)
{
    vector<float> t[n];
    
    for (int i=0; i<n; i++)
    {
       int x = n*a[i];
       t[x].push_back(a[i]);
    }
 
    for (int i=0; i<n; i++)
       sort(t[i].begin(), t[i].end());
 
    int k= 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < t[i].size(); j++)
          a[k++] = t[i][j];
}
 
int main()
{
    float a[] = {0.765, 0.324, 0.111, 0.951, 0.245, 0.48};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Elements before Sorting\n";
    for (int i=0; i<n; i++)
    cout << a[i] << " ";
    
    bucketSort(a, n);
    
    cout << "\nElements After Sorting \n";
    for (int i=0; i<n; i++)
       cout << a[i] << " ";
    return 0;
}
