// leetcode 1252 : https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

import java.util.*;

public class lc1252 {
    public int oddCells(int m, int n, int[][] indices) {
        Map<Integer, Integer> mapR = new HashMap<>();
        Map<Integer, Integer> mapC = new HashMap<>();

        int count = 0;

        for (int i = 0; i < indices.length; i++) {
            int row = indices[i][0];
            int col = indices[i][1];

            mapR.put(row, mapR.getOrDefault(row, 0) + 1);
            mapC.put(col, mapC.getOrDefault(col, 0) + 1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int rInc = mapR.getOrDefault(i, 0);
                int cInc = mapC.getOrDefault(j, 0);
                if ((rInc + cInc) % 2 != 0) {
                    count++;
                }
            }
        }

        // System.out.println("rows -> " + mapR);
        // System.out.println("cols -> " + mapC);

        return count;
    }

    public int oddCellsOptmized(int m, int n, int[][] indices) {
        int[] row = new int[m];
        int[] col = new int[n];

        for (int[] idx : indices) {
            row[idx[0]]++;
            col[idx[1]]++;
        }

        int oddRows = 0, oddCols = 0;
        for (int i = 0; i < m; i++) {
            if (row[i] % 2 != 0)
                oddRows++;
        }
        for (int j = 0; j < n; j++) {
            if (col[j] % 2 != 0)
                oddCols++;
        }

        return oddRows * (n - oddCols) + (m - oddRows) * oddCols;
    }

    public static void main(String[] args) {
        lc1252 solution = new lc1252();

        int[][] indices1 = { { 0, 1 }, { 1, 1 } };
        int result1 = solution.oddCells(2, 3, indices1);
        System.out.println("Test 1: m=2, n=3, indices=[[0,1],[1,1]] -> Output: " + result1 + " (Expected: 6)");

        int[][] indices2 = { { 1, 1 }, { 0, 0 } };
        int result2 = solution.oddCells(2, 2, indices2);
        System.out.println("Test 2: m=2, n=2, indices=[[1,1],[0,0]] -> Output: " + result2 + " (Expected: 0)");

        int[][] indices3 = { { 0, 0 } };
        int result3 = solution.oddCells(1, 1, indices3);
        System.out.println("Test 3: m=1, n=1, indices=[[0,0]] -> Output: " + result3 + " (Expected: 0)");
    }
}
