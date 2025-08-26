class GuessGame {
    private int picked;

    public GuessGame(int picked) {
        this.picked = picked;
    }

    // Simulated guess API
    public int guess(int num) {
        if (num > picked)
            return -1;
        if (num < picked)
            return 1;
        return 0;
    }
}

/**
 * Forward declaration of guess API.
 * 
 * @param num your guess
 * @return -1 if num is higher than the picked number
 *         1 if num is lower than the picked number
 *         otherwise return 0
 *         int guess(int num);
 */

public class lc374 extends GuessGame {
    public lc374(int picked) {
        super(picked);
    }

    public int guessNumber(int n) {
        int st = 0, end = n;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (guess(mid) == 0) {
                return mid;
            } else if (guess(mid) < 0) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int n = 10;
        int picked = 6;
        lc374 solution = new lc374(picked);
        int result = solution.guessNumber(n);
        System.out.println("Test 1: n = " + n + ", picked = " + picked + " -> Output: " + result + " (Expected: 6)");

        n = 100;
        picked = 73;
        solution = new lc374(picked);
        result = solution.guessNumber(n);
        System.out.println("Test 2: n = " + n + ", picked = " + picked + " -> Output: " + result + " (Expected: 73)");
    }
}