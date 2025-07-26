// leetcode 167: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Two Pointer
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return { left + 1, right + 1 }; // 1-indexed
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== TWO SUM II - INPUT ARRAY IS SORTED ===" << endl
         << endl;

    // Test Case 1
    vector<int> nums1 = { 2, 7, 11, 15 };
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test 1:" << endl;
    cout << "Input: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1)
            cout << ",";
    }
    cout << "], target = " << target1 << endl;
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl;
    cout << "Expected: [1,2]" << endl;
    cout << "Explanation: nums[0] + nums[1] = " << nums1[0] << " + " << nums1[1] << " = " << target1 << endl
         << endl;

    // Test Case 2
    vector<int> nums2 = { 2, 3, 4 };
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test 2:" << endl;
    cout << "Input: [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1)
            cout << ",";
    }
    cout << "], target = " << target2 << endl;
    cout << "Output: [" << result2[0] << "," << result2[1] << "]" << endl;
    cout << "Expected: [1,3]" << endl;
    cout << "Explanation: nums[0] + nums[2] = " << nums2[0] << " + " << nums2[2] << " = " << target2 << endl
         << endl;

    // Test Case 3
    vector<int> nums3 = { -1, 0 };
    int target3 = -1;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test 3:" << endl;
    cout << "Input: [";
    for (int i = 0; i < nums3.size(); i++) {
        cout << nums3[i];
        if (i < nums3.size() - 1)
            cout << ",";
    }
    cout << "], target = " << target3 << endl;
    cout << "Output: [" << result3[0] << "," << result3[1] << "]" << endl;
    cout << "Expected: [1,2]" << endl;
    cout << "Explanation: nums[0] + nums[1] = " << nums3[0] << " + " << nums3[1] << " = " << target3 << endl
         << endl;

    return 0;
}