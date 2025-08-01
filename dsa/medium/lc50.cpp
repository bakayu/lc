// leetcode 50 : https://leetcode.com/problems/powx-n/description/

#include <iomanip>
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n)
    {
        double num = 1.0;
        long long exp = n;
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        while (exp > 0) {
            if (exp % 2 == 1) {
                num = num * x;
            }
            x = x * x;
            exp = exp / 2;
        }

        return num;
    }
};

// RUNNER CODE
int main()
{
    Solution solution;

    cout << fixed << setprecision(5);
    cout << "=== POWER FUNCTION ===" << endl
         << endl;

    // Test case 1
    double x1 = 2.0;
    int n1 = 10;
    cout << "Test 1:" << endl;
    cout << "Input: x = " << x1 << ", n = " << n1 << endl;
    double result1 = solution.myPow(x1, n1);
    cout << "Output: " << result1 << endl;
    cout << "Expected: 1024.00000" << endl
         << endl;

    // Test case 2
    double x2 = 2.1;
    int n2 = 3;
    cout << "Test 2:" << endl;
    cout << "Input: x = " << x2 << ", n = " << n2 << endl;
    double result2 = solution.myPow(x2, n2);
    cout << "Output: " << result2 << endl;
    cout << "Expected: 9.26100" << endl
         << endl;

    // Test case 3
    double x3 = 2.0;
    int n3 = -2;
    cout << "Test 3:" << endl;
    cout << "Input: x = " << x3 << ", n = " << n3 << endl;
    double result3 = solution.myPow(x3, n3);
    cout << "Output: " << result3 << endl;
    cout << "Expected: 0.25000" << endl
         << endl;

    // Test case 4
    double x4 = 1.0;
    int n4 = 2147483647;
    cout << "Test 4:" << endl;
    cout << "Input: x = " << x4 << ", n = " << n4 << endl;
    double result4 = solution.myPow(x4, n4);
    cout << "Output: " << result4 << endl;
    cout << "Expected: 1.00000" << endl
         << endl;

    // Test case 5
    double x5 = 2.0;
    int n5 = 0;
    cout << "Test 5:" << endl;
    cout << "Input: x = " << x5 << ", n = " << n5 << endl;
    double result5 = solution.myPow(x5, n5);
    cout << "Output: " << result5 << endl;
    cout << "Expected: 1.00000" << endl
         << endl;

    // Test case 6
    double x6 = 0.5;
    int n6 = 4;
    cout << "Test 6:" << endl;
    cout << "Input: x = " << x6 << ", n = " << n6 << endl;
    double result6 = solution.myPow(x6, n6);
    cout << "Output: " << result6 << endl;
    cout << "Expected: 0.06250" << endl;
}