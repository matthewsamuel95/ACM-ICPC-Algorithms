// Given an array of integers, every element appears thrice except one. Find that single one.

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;

    for (int i = 0; i < nums.size(); i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }

    return ones;
}

int main() {
    vector<int> nums = {3, 4, 2, 3, 3, 4, 4};
    cout << singleNumber(nums) << endl;
    return 0;
}
