// leetcode 278 : https://leetcode.com/problems/first-bad-version/

/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

class VersionControl {
    private final int bad;

    public VersionControl(int bad) {
        this.bad = bad;
    }

    // Simulated isBadVersion API
    public boolean isBadVersion(int version) {
        return version >= bad;
    }
}

public class lc278 extends VersionControl {
    public lc278(int bad) {
        super(bad);
    }

    public int firstBadVersion(int n) {
        int st = 1, end = n;
        int fb = n;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isBadVersion(mid)) {
                fb = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return fb;
    }

    public static void main(String[] args) {
        int[] ns = { 5, 10, 1, 100 };
        int[] bads = { 4, 7, 1, 99 };
        int[] expected = { 4, 7, 1, 99 };

        for (int i = 0; i < ns.length; i++) {
            lc278 solution = new lc278(bads[i]);
            int result = solution.firstBadVersion(ns[i]);
            System.out.println("Test " + (i + 1) + ": n = " + ns[i] + ", first bad = " + bads[i] +
                    " -> Output: " + result + " (Expected: " + expected[i] + ")");
        }
    }
}