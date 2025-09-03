// leetcode 989 : https://leetcode.com/problems/add-to-array-form-of-integer/ 

import java.util.*;

class lc989 {
    public List<Integer> addToArrayForm(int[] num, int k) {
        int n = num.length - 1, carry = 0;
        List<Integer> arr = new ArrayList<>();

        while (k > 0 || n >= 0 || carry > 0) {
            int temp = 0;
            if (n >= 0) {
                temp = num[n];
                n--;
            }
            int sum = k % 10 + temp + carry;
            carry = sum / 10;
            arr.add(0, (sum % 10));
            k /= 10;
        }

        return arr;
    }

    public static void main(String[] args) {
        lc989 solution = new lc989();

        int[][] testCases = {
                { 1, 2, 0, 0 },
                { 2, 7, 4 },
                { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
                { 0 }
        };
        int[] kCases = { 34, 181, 1, 1000 };
        List<List<Integer>> expected = Arrays.asList(
                Arrays.asList(1, 2, 3, 4),
                Arrays.asList(4, 5, 5),
                Arrays.asList(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1),
                Arrays.asList(1, 0, 0, 0));

        for (int i = 0; i < testCases.length; i++) {
            List<Integer> result = solution.addToArrayForm(testCases[i], kCases[i]);
            System.out.println("Test " + (i + 1) + ": num = " + Arrays.toString(testCases[i]) + ", k = " + kCases[i]);
            System.out.println("Output: " + result + " (Expected: " + expected.get(i) + ")");
        }
    }
}