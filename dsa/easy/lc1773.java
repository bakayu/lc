// leetcode 1773 : https://leetcode.com/problems/count-items-matching-a-rule/

import java.util.List;

public class lc1773 {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int ruleIndex = switch (ruleKey) {
            case "type" -> 0;
            case "color" -> 1;
            case "name" -> 2;
            default -> -1;
        };

        int count = 0;
        for (List<String> ls : items) {
            if (ls.get(ruleIndex).equals(ruleValue)) {
                count++;
            }
        }

        return count;
    }
}
