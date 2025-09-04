// leetcode 1854 : https://leetcode.com/problems/maximum-population-year/description/

class lc1854 {
    public int maximumPopulation(int[][] logs) {
        int[] y = new int[101];

        for (int[] i : logs) {
            int b = i[0];
            int d = i[1];
            y[b - 1950] += 1;
            y[d - 1950] -= 1;
        }

        int max = 0;
        int maxYear = 1950;
        int cur = 0;

        for (int i = 0; i < y.length; i++) {
            cur += y[i];
            if (cur > max) {
                max = cur;
                maxYear = 1950 + i;
            }
        }

        return maxYear;
    }

    public static void main(String[] args) {
        lc1854 solution = new lc1854();

        int[][] logs1 = { { 1993, 1999 }, { 2000, 2010 } };
        int[][] logs2 = { { 1950, 1961 }, { 1960, 1971 }, { 1970, 1981 } };
        int[][] logs3 = { { 1990, 1995 }, { 1992, 1998 }, { 1994, 1999 } };
        int[][] logs4 = { { 1950, 1960 }, { 1960, 1970 }, { 1970, 1980 }, { 1980, 1990 } };

        int[] expected = { 1993, 1960, 1994, 1950 };

        int[][][] testCases = { logs1, logs2, logs3, logs4 };

        for (int i = 0; i < testCases.length; i++) {
            int result = solution.maximumPopulation(testCases[i]);
            System.out.println("Test " + (i + 1) + ": Output: " + result + " (Expected: " + expected[i] + ")");
        }
    }
}