// 1481. Least Number of Unique Integers after K Removals
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

// Example 1:

// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.
// Example 2:
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

// Constraints:

// 1 <= arr.length <= 10^5
// 1 <= arr[i] <= 10^9
// 0 <= k <= arr.length


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        

        for(int &x : arr) {

            mp[x]++;

        }

        vector<int> freq;

        

        for(auto &it : mp) {

            freq.push_back(it.second);

        }

        sort(begin(freq), end(freq));

        for(int i = 0; i < freq.size(); i++) {

    
            k -= freq[i];

            if(k < 0) {

                return freq.size() - i;

            }

        }

        
        return 0;
        
    }
};