// leetcode 1886 :
// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class lc1886 {
    private int[][] rotate(int[][] mat) {
        int n = mat.length;
        int[][] arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[j][n - i - 1] = mat[i][j];
            }
        }
        return arr;
    }

    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;
        for (int r = 0; r < 4; r++) {
            boolean ans = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != target[i][j]) {
                        ans = false;
                        break;
                    }
                }
                if (!ans) {
                    break;
                }
            }
            if (ans) {
                return true;
            }
            mat = rotate(mat);
        }

        return false;
    }

    public static void main(String[] args) {
        lc1886 solution = new lc1886();

        int[][] mat1 = {
                { 0, 1 },
                { 1, 0 }
        };
        int[][] target1 = {
                { 1, 0 },
                { 0, 1 }
        };

        int[][] mat2 = {
                { 0, 1, 0 },
                { 0, 0, 1 },
                { 1, 1, 1 }
        };
        int[][] target2 = {
                { 1, 1, 1 },
                { 0, 0, 1 },
                { 0, 1, 0 }
        };

        int[][] mat3 = {
                { 1, 1 },
                { 1, 0 }
        };
        int[][] target3 = {
                { 0, 1 },
                { 1, 1 }
        };

        boolean[] expected = { true, false, true };

        int[][][] mats = { mat1, mat2, mat3 };
        int[][][] targets = { target1, target2, target3 };

        for (int i = 0; i < mats.length; i++) {
            // Make a deep copy of the matrix for each test case
            int n = mats[i].length;
            int[][] matCopy = new int[n][n];
            for (int r = 0; r < n; r++) {
                System.arraycopy(mats[i][r], 0, matCopy[r], 0, n);
            }

            boolean result = solution.findRotation(matCopy, targets[i]);
            System.out.println("Test " + (i + 1) + ": Output: " + result + " (Expected: " + expected[i] + ")");
        }
    }
}