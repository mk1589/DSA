// 1249. Minimum Remove to Make Valid Parentheses
// Solved
// Medium
// Topics
// Companies
// Hint
// Given a string s of '(' , ')' and lowercase English characters.

// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:

// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
 

// Example 1:

// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
// Example 2:

// Input: s = "a)b(c)d"
// Output: "ab(c)d"
// Example 3:

// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is either'(' , ')', or lowercase English letter.


class Solution {
public:
    string minRemoveToMakeValid(string s) {
             int n = s.length();
        
        unordered_set<int> toRemove;
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(s[i] == '(')
                st.push(i);
            else  if(s[i] == ')') {
                if(st.empty()) { 
                    toRemove.insert(i);
                } else {
                    st.pop(); 
                }
            }
        }
        
        
        while(!st.empty()) {
            toRemove.insert(st.top());
            st.pop();
        }
        
        string result = "";
        
        for(int i = 0; i<n; i++) {
            if(toRemove.find(i) == toRemove.end())
                result.push_back(s[i]);
        }
        
        return result;
    }
};