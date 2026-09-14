class Solution {
public:
    int mySqrt(int x) {
        int left {1};
        int right {x};

        while (left <= right) {
            int mid = left + (right-left) / 2;
            if ((long long)mid*mid <= x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};