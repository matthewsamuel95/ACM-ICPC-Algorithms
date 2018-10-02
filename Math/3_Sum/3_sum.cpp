#include<bits/stdc++.h>
using namespace std;

bool compute(vector<int> arr, int sum, int coin){
	if(coin == 0 && sum == 0)return true;
	else if(coin == 0 && sum !=0) return false;
	else{
		bool triplet = false;
		for(int i = 0; i < arr.size(); i++){
			vector<int> copy = arr;
			copy.erase(copy.begin() + i);
			if(compute(copy, sum - arr[i], coin - 1)){
				triplet = true;
				break;
			}
		}
		return triplet;
	}
}

int main(){

	vector<int> arr = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0}; //input array
	int sum = 3; //desired sum
	
	bool triplet = compute(arr, sum, 3);
	
	if(triplet){
		cout << "POSSIBLE" << endl; 
	}
	else{
		cout << "Impossible" << endl;
	}
	
	return 0;
}
