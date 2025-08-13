import java.util.HashMap;
import java.util.Map;

public class lc1512 {
    public int numIdenticalPairs(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
        }

        return count;
    }

    public int numIdenticalPairsOptimized(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;

        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int ct : map.values()) {
            count += (ct * (ct - 1) / 2);
        }

        return count;

    }
}
