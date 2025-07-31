// leetcode 189 : https://leetcode.com/problems/rotate-array/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        if (k == 0) {
            return;
        }

        k = k % nums.size();

        int left = 0, right = nums.size() - 1;
        for (int i = left; i < right; i++) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }

        left = 0, right = k - 1;
        for (int i = left; i < right; i++) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }

        left = k, right = nums.size() - 1;
        for (int i = left; i < right; i++) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== ROTATE ARRAY ===" << endl
         << endl;

    // Test case 1
    vector<int> nums1 = { 1, 2, 3, 4, 5, 6, 7 };
    int k1 = 3;
    cout << "Test 1:" << endl;
    cout << "Input: nums = [1,2,3,4,5,6,7], k = " << k1 << endl;
    solution.rotate(nums1, k1);
    cout << "Output: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [5,6,7,1,2,3,4]" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { -1, -100, 3, 99 };
    int k2 = 2;
    cout << "Test 2:" << endl;
    cout << "Input: nums = [-1,-100,3,99], k = " << k2 << endl;
    solution.rotate(nums2, k2);
    cout << "Output: [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [3,99,-1,-100]" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 1 };
    int k3 = 1;
    cout << "Test 3:" << endl;
    cout << "Input: nums = [1], k = " << k3 << endl;
    solution.rotate(nums3, k3);
    cout << "Output: [";
    for (int i = 0; i < nums3.size(); i++) {
        cout << nums3[i];
        if (i < nums3.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [1]" << endl
         << endl;

    // Test case 4
    vector<int> nums4 = { 1, 2, 3, 4, 5 };
    int k4 = 7;
    cout << "Test 4:" << endl;
    cout << "Input: nums = [1,2,3,4,5], k = " << k4 << endl;
    solution.rotate(nums4, k4);
    cout << "Output: [";
    for (int i = 0; i < nums4.size(); i++) {
        cout << nums4[i];
        if (i < nums4.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [4,5,1,2,3] (k=7 is same as k=2)" << endl;

    return 0;
}