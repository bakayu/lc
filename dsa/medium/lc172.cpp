// leetcode 172 : https://leetcode.com/problems/factorial-trailing-zeroes/

#include <iostream>
using namespace std;

class Solution {
public:
    // Efficient approach - Count factors of 5
    int trailingZeroes(int n)
    {
        int count = 0;

        // Count factors of 5 in all numbers from 1 to n
        for (int i = 5; n / i > 0; i *= 5) {
            count += n / i;
        }

        return count;
    }

    // Alternative efficient approach
    int trailingZeroesAlt(int n)
    {
        int count = 0;

        while (n >= 5) {
            n /= 5;
            count += n;
        }

        return count;
    }

    // brute force
    int trailingZeroesBruteForce(int n)
    {
        if (n <= 0)
            return 0;
        if (n > 20)
            return -1; // Prevent overflow

        long long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }

        int ans = 0;
        while (fact % 10 == 0) {
            ans++;
            fact /= 10;
        }

        return ans;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << "=== FACTORIAL TRAILING ZEROES ===" << endl
         << endl;

    // Test case 1
    int n1 = 3;
    cout << "Test 1:" << endl;
    cout << "Input: n = " << n1 << endl;
    cout << "Efficient: " << solution.trailingZeroes(n1) << endl;
    cout << "Brute Force: " << solution.trailingZeroesBruteForce(n1) << endl;
    cout << "Expected: 0 (3! = 6)" << endl
         << endl;

    // Test case 2
    int n2 = 5;
    cout << "Test 2:" << endl;
    cout << "Input: n = " << n2 << endl;
    cout << "Efficient: " << solution.trailingZeroes(n2) << endl;
    cout << "Brute Force: " << solution.trailingZeroesBruteForce(n2) << endl;
    cout << "Expected: 1 (5! = 120)" << endl
         << endl;

    // Test case 3
    int n3 = 10;
    cout << "Test 3:" << endl;
    cout << "Input: n = " << n3 << endl;
    cout << "Efficient: " << solution.trailingZeroes(n3) << endl;
    cout << "Brute Force: " << solution.trailingZeroesBruteForce(n3) << endl;
    cout << "Expected: 2 (10! = 3628800)" << endl
         << endl;

    // Test case 4
    int n4 = 25;
    cout << "Test 4:" << endl;
    cout << "Input: n = " << n4 << endl;
    cout << "Efficient: " << solution.trailingZeroes(n4) << endl;
    cout << "Expected: 6" << endl
         << endl;

    // Test case 5 - Large number (brute force fails)
    int n5 = 1000;
    cout << "Test 5 - Large number:" << endl;
    cout << "Input: n = " << n5 << endl;
    cout << "Efficient: " << solution.trailingZeroes(n5) << endl;
    cout << "Expected: 249" << endl
         << endl;

    cout << "=== EXPLANATION FOR n = 25 ===" << endl;
    cout << "Numbers contributing factors of 5:" << endl;
    cout << "5, 10, 15, 20, 25" << endl;
    cout << "25 = 5² contributes 2 factors of 5" << endl;
    cout << "Total factors of 5: 1+1+1+1+2 = 6" << endl;

    return 0;
}