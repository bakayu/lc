// leetcode 1480 : https://leetcode.com/problems/running-sum-of-1d-array

import java.util.Arrays;

class lc1480 {

    public int[] runningSum(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            nums[i] = sum;
        }

        return nums;
    }

    public static void main(String[] args) {
        lc1480 sol = new lc1480();

        int[][] testCases = {
                { 1, 2, 3, 4 },
                { 1, 1, 1, 1, 1 },
                { 3, 1, 2, 10, 1 },
                { 0, 0, 0, 0 },
                { 5 },
                { -1, 2, -3, 4 }
        };

        int[][] expectedResults = {
                { 1, 3, 6, 10 },
                { 1, 2, 3, 4, 5 },
                { 3, 4, 6, 16, 17 },
                { 0, 0, 0, 0 },
                { 5 },
                { -1, 1, -2, 2 }
        };

        for (int i = 0; i < testCases.length; i++) {
            System.out.println("Test Case: \t" + Arrays.toString(testCases[i]));
            System.out.println("Expected: \t" + Arrays.toString(expectedResults[i]));
            System.out.println("Actual: \t" + Arrays.toString(sol.runningSum(testCases[i])));
            System.out.println("---");
        }
    }
}
