// leetcode 507 : https://leetcode.com/problems/perfect-number/

#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1) {
            return false;
        }

        int sum = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num % i) {
                    sum += num / i;
                }
            }
        }

        return num == sum;
    }
};

int main()
{
    Solution solution;

    cout << "=== PERFECT NUMBER ===" << endl
         << endl;

    // Test case 1
    int num1 = 28;
    cout << "Test 1:" << endl;
    cout << "Input: " << num1 << endl;
    cout << "Output: " << (solution.checkPerfectNumber(num1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl
         << endl;

    // Test case 2
    int num2 = 6;
    cout << "Test 2:" << endl;
    cout << "Input: " << num2 << endl;
    cout << "Output: " << (solution.checkPerfectNumber(num2) ? "true" : "false") << endl;
    cout << "Expected: true" << endl
         << endl;

    // Test case 3
    int num3 = 496;
    cout << "Test 3:" << endl;
    cout << "Input: " << num3 << endl;
    cout << "Output: " << (solution.checkPerfectNumber(num3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl
         << endl;

    // Test case 4
    int num4 = 12;
    cout << "Test 4:" << endl;
    cout << "Input: " << num4 << endl;
    cout << "Output: " << (solution.checkPerfectNumber(num4) ? "true" : "false") << endl;
    cout << "Expected: false" << endl
         << endl;

    // Test case 5
    int num5 = 1;
    cout << "Test 5:" << endl;
    cout << "Input: " << num5 << endl;
    cout << "Output: " << (solution.checkPerfectNumber(num5) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;

    return 0;
}