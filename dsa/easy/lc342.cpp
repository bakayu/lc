// leetcode 342: https://leetcode.com/problems/power-of-four/

#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    // Method 1: Recursive approach
    bool isPowerOfFour(int n)
    {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        if (n % 4 != 0) {
            return false;
        }
        return isPowerOfFour(n / 4);
    }

    // Method 2: Iterative approach
    bool isPowerOfFourIterative(int n)
    {
        if (n <= 0)
            return false;

        while (n % 4 == 0) {
            n /= 4;
        }

        return n == 1;
    }

    // Method 3: Bit manipulation
    bool isPowerOfFourBitwise(int n)
    {
        // Check if n > 0 and is power of 2 and has 1 in odd positions
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }

    // Method 4: Logarithmic approach
    bool isPowerOfFourLog(int n)
    {
        if (n <= 0)
            return false;

        double logResult = log(n) / log(4);
        return abs(logResult - round(logResult)) < 1e-10;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== POWER OF FOUR TESTING ===" << endl
         << endl;

    // Test cases
    int testCases[] = { 1, 4, 16, 64, 256, 1024, 2, 8, 32, 128, 0, -1, 5, 15, 17 };
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    cout << "Method 1: Recursive Approach" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < numTests; i++) {
        int n = testCases[i];
        bool result = solution.isPowerOfFour(n);
        cout << "isPowerOfFour(" << n << ") = " << (result ? "true" : "false");

        // Show the reasoning
        if (n <= 0) {
            cout << " (non-positive)";
        } else if (result) {
            cout << " (";
            int temp = n;
            int power = 0;
            while (temp > 1) {
                temp /= 4;
                power++;
            }
            cout << "4^" << power << ")";
        } else {
            cout << " (not a power of 4)";
        }
        cout << endl;
    }

    cout << endl
         << "Method 2: Iterative Approach" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < numTests; i++) {
        int n = testCases[i];
        bool result = solution.isPowerOfFourIterative(n);
        cout << "isPowerOfFourIterative(" << n << ") = " << (result ? "true" : "false") << endl;
    }

    cout << endl
         << "Method 3: Bitwise Approach" << endl;
    cout << "--------------------------" << endl;
    for (int i = 0; i < numTests; i++) {
        int n = testCases[i];
        bool result = solution.isPowerOfFourBitwise(n);
        cout << "isPowerOfFourBitwise(" << n << ") = " << (result ? "true" : "false") << endl;
    }

    cout << endl
         << "Method 4: Logarithmic Approach" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < numTests; i++) {
        int n = testCases[i];
        bool result = solution.isPowerOfFourLog(n);
        cout << "isPowerOfFourLog(" << n << ") = " << (result ? "true" : "false") << endl;
    }

    cout << endl
         << "=== POWERS OF FOUR SEQUENCE ===" << endl;
    cout << "First 8 powers of 4:" << endl;
    long long power = 1;
    for (int i = 0; i < 8; i++) {
        cout << "4^" << i << " = " << power;
        if (power <= INT_MAX) {
            cout << " -> isPowerOfFour(" << power << ") = "
                 << (solution.isPowerOfFour((int)power) ? "true" : "false");
        } else {
            cout << " (exceeds INT_MAX)";
        }
        cout << endl;
        power *= 4;
    }

    cout << endl
         << "=== COMPARISON: POWERS OF 2 vs POWERS OF 4 ===" << endl;
    cout << "Testing powers of 2 that are NOT powers of 4:" << endl;
    int powersOf2[] = { 2, 8, 32, 128, 512, 2048 };
    for (int i = 0; i < 6; i++) {
        int n = powersOf2[i];
        cout << n << " (2^" << (int)(log2(n)) << ") -> isPowerOfFour = "
             << (solution.isPowerOfFour(n) ? "true" : "false") << endl;
    }

    cout << endl
         << "=== EDGE CASES ===" << endl;
    int edgeCases[] = { INT_MAX, INT_MIN, 1073741824 }; // 1073741824 is 4^15
    for (int i = 0; i < 3; i++) {
        int n = edgeCases[i];
        bool result = solution.isPowerOfFour(n);
        cout << "isPowerOfFour(" << n << ") = " << (result ? "true" : "false");
        if (n == 1073741824)
            cout << " (4^15 - largest 32-bit power of 4)";
        cout << endl;
    }

    return 0;
}