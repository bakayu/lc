public class lc832 {
    public int[][] flipAndInvertImage(int[][] image) {
        int n = image.length;
        int[][] arr = new int[n][n];

        int ptr;
        for (int i = 0; i < n; i++) {
            ptr = n - 1;
            for (int j = 0; j < n; j++) {
                arr[i][j] = image[i][ptr] ^ 1;
                ptr--;
            }
        }

        return arr;
    }
}
