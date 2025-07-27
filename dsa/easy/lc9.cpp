// leetcode 9: https://leetcode.com/problems/palindrome-number/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revNum = 0;
        while (x > revNum) {
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }

        return (x == revNum || x == revNum / 10);
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== PALINDROME NUMBER TESTING ===" << endl
         << endl;

    // Test cases
    vector<int> testCases = { 121, -121, 10, 0, 1, 12321, 123321, 1221, 1234, 7, 11, 101, 1001 };

    for (int x : testCases) {
        bool result = solution.isPalindrome(x);
        cout << "isPalindrome(" << x << ") = " << (result ? "true" : "false") << endl;
    }

    cout << endl
         << "=== DETAILED TEST CASES ===" << endl;

    // Test case 1
    cout << "Test 1: x = 121" << endl;
    cout << "Expected: true, Got: " << (solution.isPalindrome(121) ? "true" : "false") << endl
         << endl;

    // Test case 2
    cout << "Test 2: x = -121" << endl;
    cout << "Expected: false, Got: " << (solution.isPalindrome(-121) ? "true" : "false") << endl
         << endl;

    // Test case 3
    cout << "Test 3: x = 10" << endl;
    cout << "Expected: false, Got: " << (solution.isPalindrome(10) ? "true" : "false") << endl
         << endl;

    return 0;
}