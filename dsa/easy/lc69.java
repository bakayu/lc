// leetcode 69 : https://leetcode.com/problems/sqrtx/

public class lc69 {
    public int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int start = 1, end = x / 2, ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid <= x / mid) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        lc69 solution = new lc69();

        int[] testCases = { 0, 1, 4, 8, 16, 25, 2147395599 };
        int[] expected = { 0, 1, 2, 2, 4, 5, 46339 };

        for (int i = 0; i < testCases.length; i++) {
            int result = solution.mySqrt(testCases[i]);
            System.out.println("Test " + (i + 1) + ": x = " + testCases[i] +
                    " -> Output: " + result + " (Expected: " + expected[i] + ")");
        }
    }
}
