// leetcode 209 : https://leetcode.com/problems/minimum-size-subarray-sum/

class lc209 {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE, sum = 0, j = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= target) {
                sum -= nums[j];
                ans = Math.min(ans, i - j + 1);
                j++;
            }
        }

        return ans == Integer.MAX_VALUE ? 0 : ans;
    }

    public static void main(String[] args) {
        lc209 solution = new lc209();

        int[] targets = { 7, 4, 11, 15 };
        int[][] nums = {
                { 2, 3, 1, 2, 4, 3 },
                { 1, 4, 4 },
                { 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 2, 3, 4, 5 }
        };
        int[] expected = { 2, 1, 0, 5 };

        for (int i = 0; i < targets.length; i++) {
            int result = solution.minSubArrayLen(targets[i], nums[i]);
            System.out.println(
                    "Test " + (i + 1) + ": target = " + targets[i] + ", nums = " + java.util.Arrays.toString(nums[i]) +
                            " -> Output: " + result + " (Expected: " + expected[i] + ")");
        }
    }
}
