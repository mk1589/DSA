// 3101. Count Alternating Subarrays
// Solved
// Medium
// Companies
// Hint
// You are given a 
// binary array
//  nums.

// We call a 
// subarray
//  alternating if no two adjacent elements in the subarray have the same value.

// Return the number of alternating subarrays in nums.

 

// Example 1:

// Input: nums = [0,1,1,1]

// Output: 5

// Explanation:

// The following subarrays are alternating: [0], [1], [1], [1], and [0,1].

// Example 2:

// Input: nums = [1,0,1,0]

// Output: 10

// Explanation:

// Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.

 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.



class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0; 
        int j = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                j = i;
            }
           
            count += i - j + 1;
        }
        
        return count;

    }
};