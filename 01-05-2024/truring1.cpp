#include <vector>
using namespace std;

class Solution {
public:
    vector<int> generate(int numRows) {
        vector<int> triangle;
        
        for (int i = 0; i <= numRows; ++i) {
            triangle.push_back(1); // Push first element of each row
            
            for (int j = i - 1; j > 0; --j) {
                triangle[j] += triangle[j - 1]; // Calculate other elements
            }
            
            if (i > 0) {
                triangle.push_back(1); // Push last element of each row, except the first row
            }
        }
        
        return triangle;
    }
};

// Example usage:
#include <iostream>
int main() {
    Solution sol;
    vector<int> result = sol.generate(2);
    
    // Print the result
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    
    return 0;
}
