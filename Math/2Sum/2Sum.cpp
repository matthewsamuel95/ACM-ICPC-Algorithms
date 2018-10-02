#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {

	unordered_map<int,int> mp;
	vector<int> result;

	for(int i=0; i < nums.size(); i++){
		if(mp.find(target-nums[i]) != mp.end()) {
			result.push_back(mp[target-nums[i]]);
			result.push_back(i);
			break;
		}
		else
			mp[nums[i]] = i;
	}
	return result;
}


int main() {
	
	vector<int> nums;

	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	int target = 9;

	vector<int> result = twoSum(nums,target);

	cout << result[0] << " " << result[1] << endl;

	return 0;
}
