// leetcode 53 : https://leetcode.com/problems/maximum-subarray/

class lc53 {
    // brute force
    public int maxSubArrayBrute(int[] nums) {
        int n = nums.length;
        int ans = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum > ans) {
                    ans = sum;
                }
            }
        }

        return ans;
    }

    // optimized
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }

        int ans = nums[0], max = nums[0];

        for (int i = 1; i < n; i++) {
            max = Math.max(max + nums[i], nums[i]);
            ans = Math.max(ans, max);
        }

        return ans;
    }

    public static void main(String[] args) {
        lc53 solution = new lc53();

        int[][] testCases = {
                { -2, 1, -3, 4, -1, 2, 1, -5, 4 },
                { 1 },
                { 5, 4, -1, 7, 8 },
                { -1, -2, -3, -4 },
                { 0, -1, 2, -3, 4 }
        };
        int[] expected = { 6, 1, 23, -1, 4 };

        for (int i = 0; i < testCases.length; i++) {
            int result = solution.maxSubArray(testCases[i]);
            System.out.println("Test " + (i + 1) + ": nums = " + java.util.Arrays.toString(testCases[i]) +
                    " -> Output: " + result + " (Expected: " + expected[i] + ")");
        }
    }
}