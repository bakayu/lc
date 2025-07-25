// leetcode 326 : https://leetcode.com/problems/power-of-three/

#include <iostream>
using namespace std;

class Solution {
public:
    // recursion
    bool isPowerOfThree(int n)
    {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        if (n % 3 != 0) {
            return false;
        }

        return isPowerOfThree(n / 3);
    }
};

int main()
{
    Solution solution;

    cout << "TEST CASE: 1" << endl;
    int n1 = 27;
    cout << n1 << " : " << solution.isPowerOfThree(n1) << endl;
    cout << "TEST CASE: 2" << endl;
    int n2 = 2;
    cout << n2 << " : " << solution.isPowerOfThree(n2) << endl;
    cout << "TEST CASE: 3" << endl;
    int n3 = -1;
    cout << n3 << " : " << solution.isPowerOfThree(n3) << endl;
}