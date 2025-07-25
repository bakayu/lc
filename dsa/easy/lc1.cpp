// leetcode problem: https://leetcode.com/problems/two-sum/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute Force
    vector<int> twoSumBruteForce(vector<int>& nums, int target)
    {
        std::vector<int> ans(2);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }

    // Optimized O(n) using hashmap
    vector<int> twoSumHM(vector<int>& nums, int target)
    {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                return { numMap[complement], i };
            }

            numMap[nums[i]] = i;
        }

        return {};
    }

    // Two Pointers
    vector<int> twoSumTP(vector<int>& nums, int target)
    {
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); i++) {
            indexedNums.push_back({ nums[i], i });
        }

        sort(indexedNums.begin(), indexedNums.end());

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;
            if (sum == target) {
                return { indexedNums[left].second, indexedNums[right].second };
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

    cout << "=== HASH MAP APPROACH (O(n)) ===" << endl;

    // Test case 1
    vector<int> nums1 = { 2, 7, 11, 15 };
    int target1 = 9;
    vector<int> result1 = solution.twoSumHM(nums1, target1);
    cout << "Test 1 - Input: [2,7,11,15], target: 9" << endl;
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl;
    cout << "Expected: [0,1]" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { 3, 2, 4 };
    int target2 = 6;
    vector<int> result2 = solution.twoSumHM(nums2, target2);
    cout << "Test 2 - Input: [3,2,4], target: 6" << endl;
    cout << "Output: [" << result2[0] << "," << result2[1] << "]" << endl;
    cout << "Expected: [1,2]" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 3, 3 };
    int target3 = 6;
    vector<int> result3 = solution.twoSumHM(nums3, target3);
    cout << "Test 3 - Input: [3,3], target: 6" << endl;
    cout << "Output: [" << result3[0] << "," << result3[1] << "]" << endl;
    cout << "Expected: [0,1]" << endl
         << endl;

    cout << "=== BRUTE FORCE COMPARISON (O(n²)) ===" << endl;
    vector<int> nums1_copy = { 2, 7, 11, 15 };
    vector<int> bruteResult = solution.twoSumBruteForce(nums1_copy, target1);
    cout << "Brute Force Result: [" << bruteResult[0] << "," << bruteResult[1] << "]" << endl;

    cout << "\n=== TWO POINTER APPROACH (O(n log n)) ===" << endl;

    // Test case 1 - Two Pointer
    vector<int> nums1_tp = { 2, 7, 11, 15 };
    vector<int> tpResult1 = solution.twoSumTP(nums1_tp, target1);
    cout << "Test 1 TP - Input: [2,7,11,15], target: 9" << endl;
    cout << "Output: [" << tpResult1[0] << "," << tpResult1[1] << "]" << endl;
    cout << "Expected: [0,1]" << endl
         << endl;

    // Test case 2 - Two Pointer
    vector<int> nums2_tp = { 3, 2, 4 };
    vector<int> tpResult2 = solution.twoSumTP(nums2_tp, target2);
    cout << "Test 2 TP - Input: [3,2,4], target: 6" << endl;
    cout << "Output: [" << tpResult2[0] << "," << tpResult2[1] << "]" << endl;
    cout << "Expected: [1,2]" << endl
         << endl;

    // Test case 3 - Two Pointer
    vector<int> nums3_tp = { 3, 3 };
    vector<int> tpResult3 = solution.twoSumTP(nums3_tp, target3);
    cout << "Test 3 TP - Input: [3,3], target: 6" << endl;
    cout << "Output: [" << tpResult3[0] << "," << tpResult3[1] << "]" << endl;
    cout << "Expected: [0,1]" << endl;

    return 0;
}