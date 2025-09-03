// leetcode 1217 :
// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/description/

class lc1217 {
    public int minCostToMoveChips(int[] position) {
        int odd = 0, even = 0;

        for (int i : position) {
            if (i % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        return Math.min(odd, even);
    }

    public static void main(String[] args) {
        lc1217 solution = new lc1217();

        int[][] testCases = {
                { 1, 2, 3 },
                { 2, 2, 2, 3, 3 },
                { 1, 1000000000 },
                { 1, 2, 2, 2, 3, 3, 3 }
        };
        int[] expected = { 1, 2, 1, 3 };

        for (int i = 0; i < testCases.length; i++) {
            int result = solution.minCostToMoveChips(testCases[i]);
            System.out.println("Test " + (i + 1) + ": position = " + java.util.Arrays.toString(testCases[i]) +
                    " -> Output: " + result + " (Expected: " + expected[i] + ")");
        }
    }
}