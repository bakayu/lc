// leetcode 263: https://leetcode.com/problems/ugly-number/

#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    // Method 1: Recursive approach
    bool isUgly(int n)
    {
        if (n <= 0) {
            return false;
        }

        if (n == 1) {
            return true;
        }

        return (n % 2 == 0) ? isUgly(n / 2) : (n % 3 == 0) ? isUgly(n / 3)
            : (n % 5 == 0)                                 ? isUgly(n / 5)
                                                           : false;
    }

    // Method 2: Iterative approach
    bool isUglyIterative(int n)
    {
        if (n <= 0)
            return false;

        // Divide by 2, 3, 5 as much as possible
        while (n % 2 == 0)
            n /= 2;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;

        // If only 2, 3, 5 factors existed, n should be 1 now
        return n == 1;
    }

    // Method 3: Helper function approach
    bool isUglyHelper(int n)
    {
        if (n <= 0)
            return false;

        int factors[] = { 2, 3, 5 };
        for (int factor : factors) {
            while (n % factor == 0) {
                n /= factor;
            }
        }

        return n == 1;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== UGLY NUMBER TESTING ===" << endl
         << endl;

    // Test cases
    int testCases[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 20, 25, 30, 0, -1 };
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    cout << "Method 1: Recursive Approach" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < numTests; i++) {
        int n = testCases[i];
        bool result = solution.isUgly(n);
        cout << "isUgly(" << n << ") = " << (result ? "true" : "false");

        // Show factorization for positive numbers
        if (n > 0 && result) {
            cout << " (factors: ";
            int temp = n;
            bool first = true;

            while (temp % 2 == 0) {
                if (!first)
                    cout << " × ";
                cout << "2";
                temp /= 2;
                first = false;
            }
            while (temp % 3 == 0) {
                if (!first)
                    cout << " × ";
                cout << "3";
                temp /= 3;
                first = false;
            }
            while (temp % 5 == 0) {
                if (!first)
                    cout << " × ";
                cout << "5";
                temp /= 5;
                first = false;
            }
            if (first)
                cout << "1"; // n was 1
            cout << ")";
        } else if (n > 0 && !result) {
            cout << " (has other prime factors)";
        }
        cout << endl;
    }

    cout << endl
         << "Method 2: Iterative Approach" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < numTests; i++) {
        int n = testCases[i];
        bool result = solution.isUglyIterative(n);
        cout << "isUglyIterative(" << n << ") = " << (result ? "true" : "false") << endl;
    }

    cout << endl
         << "Method 3: Helper Function Approach" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < numTests; i++) {
        int n = testCases[i];
        bool result = solution.isUglyHelper(n);
        cout << "isUglyHelper(" << n << ") = " << (result ? "true" : "false") << endl;
    }

    cout << endl
         << "=== FIRST 20 UGLY NUMBERS ===" << endl;
    cout << "Sequence of ugly numbers:" << endl;
    int count = 0;
    int num = 1;
    while (count < 20) {
        if (solution.isUgly(num)) {
            cout << count + 1 << ": " << num << endl;
            count++;
        }
        num++;
    }

    cout << endl
         << "=== ANALYSIS OF NON-UGLY NUMBERS ===" << endl;
    cout << "Numbers with prime factors other than 2, 3, 5:" << endl;
    int nonUglyExamples[] = { 7, 11, 13, 14, 17, 19, 21, 22, 23, 26 };
    for (int i = 0; i < 10; i++) {
        int n = nonUglyExamples[i];
        cout << n << " -> isUgly = " << (solution.isUgly(n) ? "true" : "false");

        // Show why it's not ugly
        if (n == 7)
            cout << " (prime factor: 7)";
        else if (n == 11)
            cout << " (prime factor: 11)";
        else if (n == 13)
            cout << " (prime factor: 13)";
        else if (n == 14)
            cout << " (14 = 2 × 7, has prime factor 7)";
        else if (n == 17)
            cout << " (prime factor: 17)";
        else if (n == 19)
            cout << " (prime factor: 19)";
        else if (n == 21)
            cout << " (21 = 3 × 7, has prime factor 7)";
        else if (n == 22)
            cout << " (22 = 2 × 11, has prime factor 11)";
        else if (n == 23)
            cout << " (prime factor: 23)";
        else if (n == 26)
            cout << " (26 = 2 × 13, has prime factor 13)";

        cout << endl;
    }

    cout << endl
         << "=== EDGE CASES ===" << endl;
    int edgeCases[] = { INT_MAX, 1000000000, 536870912 }; // 536870912 = 2^29
    for (int i = 0; i < 3; i++) {
        int n = edgeCases[i];
        bool result = solution.isUgly(n);
        cout << "isUgly(" << n << ") = " << (result ? "true" : "false");
        if (n == 536870912)
            cout << " (2^29)";
        cout << endl;
    }

    return 0;
}