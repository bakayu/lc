
// leetcode 35 : https://leetcode.com/problems/search-insert-position/

public class lc35 {
    public int searchInsert(int[] nums, int target) {
        int n = nums.length;
        int st = 0, end = n - 1;
        int mid = st + (end - st) / 2;
        boolean inc = false;

        while (st <= end) {
            mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
                if (inc) {
                    inc = !inc;
                }
            } else {
                st = mid + 1;
                if (!inc) {
                    inc = !inc;
                }
            }
        }
        return inc ? mid + 1 : mid;
    }
}
