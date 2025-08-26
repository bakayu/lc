// leetcode 1572 : https://leetcode.com/problems/matrix-diagonal-sum/

public class lc1572 {
    public int diagonalSum(int[][] mat) {
        int sum = 0;
        int n = mat.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) {
                    sum += mat[i][j];
                }
            }
        }

        return sum;
    }

    public int diagonalSumOptimized(int[][] arr) {
        int sum = 0;
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            sum += arr[i][i];
            sum += arr[i][n - 1 - i];
        }

        if (n % 2 != 0) {
            int mid = arr[n / 2][n / 2];
            sum -= mid;
        }

        return sum;
    }

    public static void main(String[] args) {
        lc1572 solution = new lc1572();

        int[][] mat1 = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 }
        };
        System.out.println("Test 1: Expected: 25, Output: " + solution.diagonalSum(mat1));

        int[][] mat2 = {
                { 5 }
        };
        System.out.println("Test 2: Expected: 5, Output: " + solution.diagonalSum(mat2));

        int[][] mat3 = {
                { 1, 0, 0, 1 },
                { 0, 2, 2, 0 },
                { 0, 3, 3, 0 },
                { 4, 0, 0, 4 }
        };
        System.out.println("Test 3: Expected: 14, Output: " + solution.diagonalSum(mat3));
    }
}