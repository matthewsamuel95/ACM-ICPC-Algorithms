// Given an array of integers, every element appears twice except one. Find that single one.

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int single_number = 0;

    for (const auto &i : nums)
        single_number ^= i;

    return single_number;
}

int main() {
    vector<int> nums = {3, 4, 2, 1, 3, 1, 4};
    cout << singleNumber(nums) << endl;
    return 0;
}
