// leetcode 1920 : https://leetcode.com/problems/build-array-from-permutation/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== BUILD ARRAY FROM PERMUTATION ===" << endl
         << endl;

    // Test case 1
    vector<int> nums1 = { 0, 2, 1, 5, 3, 4 };
    cout << "Test 1:" << endl;
    cout << "Input: [0,2,1,5,3,4]" << endl;
    vector<int> result1 = solution.buildArray(nums1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [0,1,2,4,5,3]" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { 5, 0, 1, 2, 3, 4 };
    cout << "Test 2:" << endl;
    cout << "Input: [5,0,1,2,3,4]" << endl;
    vector<int> result2 = solution.buildArray(nums2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [4,5,0,1,2,3]" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 0 };
    cout << "Test 3:" << endl;
    cout << "Input: [0]" << endl;
    vector<int> result3 = solution.buildArray(nums3);
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [0]" << endl;

    return 0;
}