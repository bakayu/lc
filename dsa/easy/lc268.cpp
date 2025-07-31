// leetcode 268 : https://leetcode.com/problems/missing-number/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int actual_sum = 0;
        for (int i = 0; i < n; i++) {
            actual_sum += nums[i];
        }

        return sum - actual_sum;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== MISSING NUMBER ===" << endl
         << endl;

    // Test case 1
    vector<int> nums1 = { 3, 0, 1 };
    cout << "Test 1:" << endl;
    cout << "Input: [3,0,1]" << endl;
    int result1 = solution.missingNumber(nums1);
    cout << "Output: " << result1 << endl;
    cout << "Expected: 2" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { 0, 1 };
    cout << "Test 2:" << endl;
    cout << "Input: [0,1]" << endl;
    int result2 = solution.missingNumber(nums2);
    cout << "Output: " << result2 << endl;
    cout << "Expected: 2" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
    cout << "Test 3:" << endl;
    cout << "Input: [9,6,4,2,3,5,7,0,1]" << endl;
    int result3 = solution.missingNumber(nums3);
    cout << "Output: " << result3 << endl;
    cout << "Expected: 8" << endl
         << endl;

    // Test case 4
    vector<int> nums4 = { 0 };
    cout << "Test 4:" << endl;
    cout << "Input: [0]" << endl;
    int result4 = solution.missingNumber(nums4);
    cout << "Output: " << result4 << endl;
    cout << "Expected: 1" << endl
         << endl;

    // Test case 5
    vector<int> nums5 = { 1 };
    cout << "Test 5:" << endl;
    cout << "Input: [1]" << endl;
    int result5 = solution.missingNumber(nums5);
    cout << "Output: " << result5 << endl;
    cout << "Expected: 0" << endl;

    return 0;
}