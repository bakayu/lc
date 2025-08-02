// leetcode 15 : https://leetcode.com/problems/3sum/description/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({ nums[i], nums[left], nums[right] });
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== 3SUM ===" << endl
         << endl;

    // Test case 1
    vector<int> nums1 = { -1, 0, 1, 2, -1, -4 };
    cout << "Test 1:" << endl;
    cout << "Input: [-1,0,1,2,-1,-4]" << endl;
    vector<vector<int>> result1 = solution.threeSum(nums1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j];
            if (j < result1[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < result1.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [[-1,-1,2],[-1,0,1]]" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { 0, 1, 1 };
    cout << "Test 2:" << endl;
    cout << "Input: [0,1,1]" << endl;
    vector<vector<int>> result2 = solution.threeSum(nums2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result2[i].size(); j++) {
            cout << result2[i][j];
            if (j < result2[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < result2.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: []" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 0, 0, 0 };
    cout << "Test 3:" << endl;
    cout << "Input: [0,0,0]" << endl;
    vector<vector<int>> result3 = solution.threeSum(nums3);
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result3[i].size(); j++) {
            cout << result3[i][j];
            if (j < result3[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < result3.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [[0,0,0]]" << endl;

    return 0;
}