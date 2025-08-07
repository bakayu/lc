// leetcode 11 : https://leetcode.com/problems/container-with-most-water/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            max_area = max(max_area, h * w);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== CONTAINER WITH MOST WATER ===" << endl
         << endl;

    // Test case 1
    vector<int> heights1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << "Test 1:" << endl;
    cout << "Input: [1,8,6,2,5,4,8,3,7]" << endl;
    cout << "Output: " << solution.maxArea(heights1) << endl;
    cout << "Expected: 49" << endl
         << endl;

    // Test case 2
    vector<int> heights2 = { 1, 1 };
    cout << "Test 2:" << endl;
    cout << "Input: [1,1]" << endl;
    cout << "Output: " << solution.maxArea(heights2) << endl;
    cout << "Expected: 1" << endl
         << endl;

    // Test case 3
    vector<int> heights3 = { 4, 3, 2, 1, 4 };
    cout << "Test 3:" << endl;
    cout << "Input: [4,3,2,1,4]" << endl;
    cout << "Output: " << solution.maxArea(heights3) << endl;
    cout << "Expected: 16" << endl
         << endl;

    // Test case 4
    vector<int> heights4 = { 1, 2, 1 };
    cout << "Test 4:" << endl;
    cout << "Input: [1,2,1]" << endl;
    cout << "Output: " << solution.maxArea(heights4) << endl;
    cout << "Expected: 2" << endl;

    return 0;
}