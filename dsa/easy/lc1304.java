// leetcode 1304 :
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

class lc1304 {

    public int[] sumZero(int n) {
        int[] arr = new int[n];
        if (n == 1) {
            arr[0] = 0;
            return arr;
        }

        for (int i = 1; i < n; i += 2) {
            arr[i - 1] = i;
            arr[i] = -i;
        }

        if (n % 2 != 0) {
            arr[n - 1] = 0;
        }

        return arr;
    }

    public static void main(String[] args) {
        lc1304 solution = new lc1304();

        int[] testCases = { 1, 2, 3, 4, 5 };
        int[][] expected = {
                { 0 },
                { -1, 1 },
                { -1, 0, 1 },
                { -3, -1, 1, 3 },
                { -2, -1, 0, 1, 2 }
        };

        for (int i = 0; i < testCases.length; i++) {
            int[] result = solution.sumZero(testCases[i]);
            System.out.print("Test " + (i + 1) + ": n = " + testCases[i] + " -> Output: [");
            for (int j = 0; j < result.length; j++) {
                System.out.print(result[j]);
                if (j < result.length - 1)
                    System.out.print(", ");
            }
            System.out.print("] (Expected: [");
            for (int j = 0; j < expected[i].length; j++) {
                System.out.print(expected[i][j]);
                if (j < expected[i].length - 1)
                    System.out.print(", ");
            }
            System.out.println("])");
        }
    }
}