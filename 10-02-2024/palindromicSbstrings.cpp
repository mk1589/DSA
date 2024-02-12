// 647. Palindromic Substrings
// Medium
// Topics
// Companies
// Hint
// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.00000

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

// #include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool check(string& s, int i, int j) {
        if (i > j) {
            return true;
        }
        if (s[i] == s[j]) {
            return check(s, ++i, --j);
        }
        return false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};




class Solution {
public:
    int t[1001][1001];
    bool check(string& s, int i, int j) {
        if (i > j) {
            return true;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if (s[i] == s[j]) {
            return t[i][j] = check(s, i+1, j-1);
        }
        return t[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        memset(t,-1,sizeof(t));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    string input = "abc";
    int result = solution.countSubstrings(input);
    cout<<result<<endl;
    return 0;
}