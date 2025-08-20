package dsa.hard;

class lc42 {
    public int trap(int[] arr) {
        int[] LM = new int[arr.length];
        int[] RM = new int[arr.length];
        int left = 0, right = arr.length - 1, lmax = 0, rmax = 0;
        int[] water = new int[arr.length];

        for (int i = 0; i < arr.length; i++) {
            lmax = Math.max(lmax, arr[left]);
            LM[left] = lmax;

            rmax = Math.max(rmax, arr[right]);
            RM[right] = Math.max(rmax, arr[right]);

            left++;
            right--;
        }

        for (int i = 0; i < arr.length; i++) {
            water[i] = Math.min(LM[i], RM[i]);
        }

        int ans = 0;
        for (int i = 0; i < arr.length; i++) {
            ans += water[i] - arr[i];
        }

        return ans;

    }

    public static void main(String[] args) {
        dsa.hard.lc42 solution = new dsa.hard.lc42();

        int[][] testCases = {
                { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 },
                { 4, 2, 0, 3, 2, 5 },
                { 2, 0, 2 },
                { 3, 0, 0, 2, 0, 4 }
        };
        int[] expected = { 6, 9, 2, 10 };

        for (int i = 0; i < testCases.length; i++) {
            int result = solution.trap(testCases[i]);
            System.out.println("Test " + (i + 1) + ": arr = " + java.util.Arrays.toString(testCases[i]) +
                    " -> Output: " + result + " (Expected: " + expected[i] + ")");
        }
    }
}