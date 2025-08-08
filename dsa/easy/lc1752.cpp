// leetcode 172 : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums)
    {
        int pivot = 0;
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (temp > nums[i]) {
                pivot = i;
                break;
            }
        }

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = nums[(i + pivot) % nums.size()];
        }

        return is_sorted(ans.begin(), ans.end()) ? true : false;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    vector<vector<int>> testCases = {
        { 3, 4, 5, 1, 2 },
        { 1, 2, 3, 4, 5 },
        { 2, 1, 3, 4 },
        { 6, 10, 6 }
    };

    vector<string> expected = {
        "true", // [3,4,5,1,2] is sorted and rotated
        "true", // [1,2,3,4,5] is sorted (no rotation)
        "false", // [2,1,3,4] is not sorted and rotated
        "false" // [6,10,6] is not sorted and rotated
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Test " << i + 1 << ": [";
        for (size_t j = 0; j < testCases[i].size(); ++j) {
            cout << testCases[i][j];
            if (j < testCases[i].size() - 1)
                cout << ",";
        }
        cout << "] -> ";
        string result = solution.check(testCases[i]) ? "true" : "false";
        cout << result << " (Expected: " << expected[i] << ")" << endl;
    }
    return 0;
}