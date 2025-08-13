import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class lc1431 {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int n = Arrays.stream(candies).max().getAsInt();
        List<Boolean> arr = new ArrayList<>();

        for (int i = 0; i < candies.length; i++) {
            if (candies[i] + extraCandies >= n) {
                arr.add(true);
            } else {
                arr.add(false);
            }
        }

        return arr;
    }
}

class Main {
    public static void main(String[] args) {
        lc1431 solution = new lc1431();

        int[][] testCases = {
                { 2, 3, 5, 1, 3 },
                { 4, 2, 1, 1, 2 },
                { 12, 1, 12 },
                { 1, 2, 3, 4, 5 }
        };
        int[] extras = { 3, 1, 10, 2 };

        for (int i = 0; i < testCases.length; i++) {
            System.out.print("Test " + (i + 1) + ": candies = " + Arrays.toString(testCases[i]) + ", extraCandies = "
                    + extras[i] + " -> ");
            System.out.println(solution.kidsWithCandies(testCases[i], extras[i]));
        }
    }
}