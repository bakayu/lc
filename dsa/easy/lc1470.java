class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] arr = new int[2 * n];
        int left = 0;
        int right = n;

        for (int i = 0; i < 2 * n; i += 2) {
            arr[i] = nums[left];
            arr[i + 1] = nums[right];
            left++;
            right++;
        }

        return arr;
    }
}