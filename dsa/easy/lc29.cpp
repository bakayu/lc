// leetcode 26: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int temp = nums[0];
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (temp == nums[i]) {
                continue;
            }
            temp = nums[i];
            k++;
            nums[k] = nums[i];
        }
        return k + 1;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== REMOVE DUPLICATES FROM SORTED ARRAY ===" << endl
         << endl;

    // Test case 1
    vector<int> nums1 = { 1, 1, 2 };
    cout << "Test 1:" << endl;
    cout << "Input: [1,1,2]" << endl;
    int k1 = solution.removeDuplicates(nums1);
    cout << "Output: k = " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i];
        if (i < k1 - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: k = 2, nums = [1,2]" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    cout << "Test 2:" << endl;
    cout << "Input: [0,0,1,1,1,2,2,3,3,4]" << endl;
    int k2 = solution.removeDuplicates(nums2);
    cout << "Output: k = " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i];
        if (i < k2 - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: k = 5, nums = [0,1,2,3,4]" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 1 };
    cout << "Test 3:" << endl;
    cout << "Input: [1]" << endl;
    int k3 = solution.removeDuplicates(nums3);
    cout << "Output: k = " << k3 << ", nums = [";
    for (int i = 0; i < k3; i++) {
        cout << nums3[i];
        if (i < k3 - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: k = 1, nums = [1]" << endl
         << endl;

    // Test case 4
    vector<int> nums4 = { 1, 2, 3, 4, 5 };
    cout << "Test 4:" << endl;
    cout << "Input: [1,2,3,4,5]" << endl;
    int k4 = solution.removeDuplicates(nums4);
    cout << "Output: k = " << k4 << ", nums = [";
    for (int i = 0; i < k4; i++) {
        cout << nums4[i];
        if (i < k4 - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: k = 5, nums = [1,2,3,4,5]" << endl;

    return 0;
}