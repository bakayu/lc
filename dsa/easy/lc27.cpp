// leetcode 27 : https://leetcode.com/problems/remove-element/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== REMOVE ELEMENT ===" << endl
         << endl;

    // Test case 1
    vector<int> nums1 = { 3, 2, 2, 3 };
    int val1 = 3;
    cout << "Test 1:" << endl;
    cout << "Input: nums = [3,2,2,3], val = " << val1 << endl;
    int k1 = solution.removeElement(nums1, val1);
    cout << "Output: k = " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i];
        if (i < k1 - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: k = 2, nums = [2,2]" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val2 = 2;
    cout << "Test 2:" << endl;
    cout << "Input: nums = [0,1,2,2,3,0,4,2], val = " << val2 << endl;
    int k2 = solution.removeElement(nums2, val2);
    cout << "Output: k = " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i];
        if (i < k2 - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: k = 5, nums = [0,1,3,0,4]" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 1 };
    int val3 = 1;
    cout << "Test 3:" << endl;
    cout << "Input: nums = [1], val = " << val3 << endl;
    int k3 = solution.removeElement(nums3, val3);
    cout << "Output: k = " << k3 << ", nums = [";
    for (int i = 0; i < k3; i++) {
        cout << nums3[i];
        if (i < k3 - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: k = 0, nums = []" << endl
         << endl;

    // Test case 4
    vector<int> nums4 = { 4, 5, 6, 7 };
    int val4 = 8;
    cout << "Test 4:" << endl;
    cout << "Input: nums = [4,5,6,7], val = " << val4 << endl;
    int k4 = solution.removeElement(nums4, val4);
    cout << "Output: k = " << k4 << ", nums = [";
    for (int i = 0; i < k4; i++) {
        cout << nums4[i];
        if (i < k4 - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: k = 4, nums = [4,5,6,7]" << endl;

    return 0;
}