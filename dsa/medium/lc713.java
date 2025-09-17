// leetcode 713 : https://leetcode.com/problems/subarray-product-less-than-k/

class lc713 {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) {
            return 0;
        }

        int n = nums.length;
        int j = 0, ans = 0, prod = 1;

        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            while (prod >= k) {
                prod /= nums[j];
                j++;
            }
            ans += i - j + 1;
        }

        return ans;
    }

    public static void main(String[] args) {
        lc713 solution = new lc713();

        int[][] testCases = {
                { 10, 5, 2, 6 },
                { 1, 2, 3 },
                { 1, 1, 1 },
                { 100, 200, 300 }
        };
        int[] kCases = { 100, 0, 2, 1000 };
        int[] expected = { 8, 0, 6, 6 };

        for (int i = 0; i < testCases.length; i++) {
            int result = solution.numSubarrayProductLessThanK(testCases[i], kCases[i]);
            System.out.println(
                    "Test " + (i + 1) + ": nums = " + java.util.Arrays.toString(testCases[i]) + ", k = " + kCases[i] +
                            " -> Output: " + result + " (Expected: " + expected[i] + ")");
        }
    }
}
