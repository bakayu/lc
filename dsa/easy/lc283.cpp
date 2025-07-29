// leetcode 283 : https://leetcode.com/problems/move-zeroes/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[k] = nums[i];
                k++;
            }
        }
        for (int i = k; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== MOVE ZEROES ===" << endl
         << endl;

    // Test case 1
    vector<int> nums1 = { 0, 1, 0, 3, 12 };
    cout << "Test 1:" << endl;
    cout << "Input: [0,1,0,3,12]" << endl;
    solution.moveZeroes(nums1);
    cout << "Output: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [1,3,12,0,0]" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { 0 };
    cout << "Test 2:" << endl;
    cout << "Input: [0]" << endl;
    solution.moveZeroes(nums2);
    cout << "Output: [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [0]" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 1, 2, 3, 4, 5 };
    cout << "Test 3:" << endl;
    cout << "Input: [1,2,3,4,5]" << endl;
    solution.moveZeroes(nums3);
    cout << "Output: [";
    for (int i = 0; i < nums3.size(); i++) {
        cout << nums3[i];
        if (i < nums3.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [1,2,3,4,5]" << endl
         << endl;

    // Test case 4
    vector<int> nums4 = { 0, 0, 0, 1, 2 };
    cout << "Test 4:" << endl;
    cout << "Input: [0,0,0,1,2]" << endl;
    solution.moveZeroes(nums4);
    cout << "Output: [";
    for (int i = 0; i < nums4.size(); i++) {
        cout << nums4[i];
        if (i < nums4.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [1,2,0,0,0]" << endl;

    return 0;
}