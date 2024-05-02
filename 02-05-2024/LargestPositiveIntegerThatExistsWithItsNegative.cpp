// 2441. Largest Positive Integer That Exists With Its Negative
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

// Return the positive integer k. If there is no such integer, return -1.

 

// Example 1:

// Input: nums = [-1,2,-3,3]
// Output: 3
// Explanation: 3 is the only valid k we can find in the array.
// Example 2:

// Input: nums = [-1,10,6,7,-7,1]
// Output: 7
// Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
// Example 3:

// Input: nums = [-10,8,6,7,-2,-3]
// Output: -1
// Explanation: There is no a single valid k, we return -1.
 

// Constraints:

// 1 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// nums[i] != 0

#include <bits/stdc++.h>


class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        
        while(i < j) {
            if(-nums[i] == nums[j]) {
                return nums[j];
            } else if(-nums[i] < nums[j]) {
                j--;
            } else {
                i++;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 3, 5, 6, 9, 12, 13, 15, 17, -6, -5, -3, -1}; // Example input
    int maxK = solution.findMaxK(nums);
    std::cout << "Max K value: " << maxK << std::endl;
    return 0;
}
