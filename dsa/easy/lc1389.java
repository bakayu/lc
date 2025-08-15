// Leetcode 1389 : https://leetcode.com/problems/create-target-array-in-the-given-order

import java.util.ArrayList;
import java.util.List;

public class lc1389 {
    public int[] createTargetArray(int[] nums, int[] index) {
        List<Integer> arr = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            arr.add(index[i], nums[i]);
        }

        int[] ans = new int[arr.size()];
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = arr.get(i);
        }

        return ans;
    }
}
