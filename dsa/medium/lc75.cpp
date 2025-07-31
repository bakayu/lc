// leetcode 75 : https://leetcode.com/problems/sort-colors

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int low, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== SORT COLORS ===" << endl
         << endl;

    // Test case 1
    vector<int> nums1 = { 2, 0, 2, 1, 1, 0 };
    cout << "Test 1:" << endl;
    cout << "Input: [2,0,2,1,1,0]" << endl;
    solution.sortColors(nums1);
    cout << "Output: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [0,0,1,1,2,2]" << endl
         << endl;

    // Test case 2
    vector<int> nums2 = { 2, 0, 1 };
    cout << "Test 2:" << endl;
    cout << "Input: [2,0,1]" << endl;
    solution.sortColors(nums2);
    cout << "Output: [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [0,1,2]" << endl
         << endl;

    // Test case 3
    vector<int> nums3 = { 0 };
    cout << "Test 3:" << endl;
    cout << "Input: [0]" << endl;
    solution.sortColors(nums3);
    cout << "Output: [";
    for (int i = 0; i < nums3.size(); i++) {
        cout << nums3[i];
        if (i < nums3.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [0]" << endl
         << endl;

    // Test case 4
    vector<int> nums4 = { 1 };
    cout << "Test 4:" << endl;
    cout << "Input: [1]" << endl;
    solution.sortColors(nums4);
    cout << "Output: [";
    for (int i = 0; i < nums4.size(); i++) {
        cout << nums4[i];
        if (i < nums4.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [1]" << endl
         << endl;

    // Test case 5
    vector<int> nums5 = { 2, 2, 2, 1, 1, 0 };
    cout << "Test 5:" << endl;
    cout << "Input: [2,2,2,1,1,0]" << endl;
    solution.sortColors(nums5);
    cout << "Output: [";
    for (int i = 0; i < nums5.size(); i++) {
        cout << nums5[i];
        if (i < nums5.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [0,1,1,2,2,2]" << endl;

    return 0;
}