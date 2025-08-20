class lc162 {
    public int findPeakElement(int[] arr) {
        int n = arr.length;
        int st = 0, end = n - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (mid < end && arr[mid] < arr[mid + 1])
                st = mid + 1;
            else if (mid < end && arr[mid] > arr[mid + 1])
                end = mid;
            else
                return mid;
        }
        return st;
    }
}