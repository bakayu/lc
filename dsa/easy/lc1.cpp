// leetcode problem: https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::vector<int> ans(2);

        for (int i = 0; i < nums.size(); i++) {
            int num1 = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int num2 = nums[j];
                if (num1 + num2 == target) {
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = { 2, 7, 11, 15 };
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test 1 - Input: [2,7,11,15], target: 9" << endl;
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl;
    cout << "Expected: [0,1]" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { 3, 2, 4 };
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test 2 - Input: [3,2,4], target: 6" << endl;
    cout << "Output: [" << result2[0] << "," << result2[1] << "]" << endl;
    cout << "Expected: [1,2]" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 3, 3 };
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test 3 - Input: [3,3], target: 6" << endl;
    cout << "Output: [" << result3[0] << "," << result3[1] << "]" << endl;
    cout << "Expected: [0,1]" << endl;

    return 0;
}