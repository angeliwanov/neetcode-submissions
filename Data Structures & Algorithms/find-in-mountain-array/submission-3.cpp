/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(0, mountainArr.length() - 1, mountainArr);
        int left = bs(0, peak, mountainArr, target);
        int right = bsr(peak, mountainArr.length() - 1, mountainArr, target);

        return left != -1 ? left : right;
    }

    int findPeak(int left, int right, MountainArray& mA) {
        while (left <= right) {
            int mid {left + (right - left) / 2};
            cout << left << ", " << right << endl;
            if ((mid == 0 || mA.get(mid) > mA.get(mid-1)) && (mid == mA.length() - 1 || mA.get(mid) > mA.get(mid+1))) {
                return mid;
            } else if (mA.get(mid) < mA.get(mid+1)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    int bs(int left, int right, MountainArray& mA, int& target) {
        while (left <= right) {
            int mid {left + (right - left) / 2};
            if (mA.get(mid) == target) {
                return mid;
            } else if (mA.get(mid) > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    int bsr(int left, int right, MountainArray& mA, int& target) {
        while (left <= right) {
            int mid {left + (right - left) / 2};
            if (mA.get(mid) == target) {
                return mid;
            } else if (mA.get(mid) > target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};