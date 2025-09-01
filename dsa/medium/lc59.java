// leetcode 59 : https://leetcode.com/problems/spiral-matrix-ii/

class lc59 {
    public int[][] generateMatrix(int n) {
        int[][] arr = new int[n][n];
        int num = 1;

        int top = 0, bottom = n - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                arr[top][i] = num;
                num++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                arr[i][right] = num;
                num++;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    arr[bottom][i] = num;
                    num++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    arr[i][left] = num;
                    num++;
                }
                left++;
            }
        }

        return arr;
    }

    public static void main(String[] args) {
        lc59 solution = new lc59();

        int[] testCases = { 1, 2, 3, 4 };
        int[][][] expected = {
                { { 1 } },
                { { 1, 2 }, { 4, 3 } },
                { { 1, 2, 3 }, { 8, 9, 4 }, { 7, 6, 5 } },
                { { 1, 2, 3, 4 }, { 12, 13, 14, 5 }, { 11, 16, 15, 6 }, { 10, 9, 8, 7 } }
        };

        for (int t = 0; t < testCases.length; t++) {
            int[][] result = solution.generateMatrix(testCases[t]);
            System.out.println("Test " + (t + 1) + ": n = " + testCases[t]);
            System.out.println("Output:");
            for (int[] result1 : result) {
                for (int j = 0; j < result1.length; j++) {
                    System.out.print(result1[j] + " ");
                }
                System.out.println();
            }
            System.out.println("Expected:");
            for (int[] item : expected[t]) {
                for (int j = 0; j < item.length; j++) {
                    System.out.print(item[j] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}