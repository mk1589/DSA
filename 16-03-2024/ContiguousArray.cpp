// 525. Contiguous Array
// Medium

// 7797

// 362

// Add to List

// Share
// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        freqMap[0] = -1; 
        int maxLength = 0;
        int count = 0; 

        for (int i = 0; i < nums.size(); i++) {
            
            count += (nums[i] == 0 ? -1 : 1);

            if (freqMap.find(count) != freqMap.end()) {
                maxLength = max(maxLength, i - freqMap[count]);
            } else {
                
                freqMap[count] = i;
            }
        }

        return maxLength;
    }
};