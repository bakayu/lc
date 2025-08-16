// leetcode 1832 - https://leetcode.com/problems/check-if-the-sentence-is-pangram/

import java.util.*;

class lc1832 {
    public boolean checkIfPangram(String sentence) {
        Map<Character, Integer> map = new HashMap<>();

        for (char i : sentence.toCharArray()) {
            map.putIfAbsent(i, 1);
        }

        return map.size() == 26;
    }
}