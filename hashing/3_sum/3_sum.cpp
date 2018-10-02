#include <bits/stdc++.h> 
using namespace std; 
 
bool find3Numbers(int A[], int arr_size, int sum) 
{ 
	
	for (int i = 0; i < arr_size - 2; i++) { 

		
		unordered_set<int> s; 
		int curr_sum = sum - A[i]; 
		for (int j = i + 1; j < arr_size; j++) { 
			if (s.find(curr_sum - A[j]) != s.end()) 
			{
			    cout<<A[i]<<" "<<curr_sum-A[j]<<" "<<A[j]<<endl;
				return true; 
			}
			s.insert(A[j]); 
		} 
	} 

	return false; 
} 

int main() 
{
    int n;
    cin>>n;
    int A[n] ; 
	
	for(int i=0;i<n;i++)
	    cin>>A[i];
	   
	int sum;
	cin>>sum;
	

	if (find3Numbers(A, n, sum)) 
	{
	    return 0;
	}
	else
		cout << "No Such Triplet"; 

	return 0; 
} 

