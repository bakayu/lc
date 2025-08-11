public class lc1672 {
    public int maximumWealth(int[][] accounts) {
        int maxSum = 0;
        for (int[] arr : accounts) {
            int arrSum = 0;
            for (int i : arr) {
                arrSum += i;
            }
            if (arrSum > maxSum) {
                maxSum = arrSum;
            }
        }

        return maxSum;
    }
}
