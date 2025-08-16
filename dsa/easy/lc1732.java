// leetcode 1732 : https://leetcode.com/problems/find-the-highest-altitude/

public class lc1732 {
    public int largestAltitude(int[] gain) {
        int alt = 0;
        int highestAlt = 0;
        for (int i : gain) {
            alt += i;
            if (alt > highestAlt) {
                highestAlt = alt;
            }
        }

        return highestAlt;
    }
}
