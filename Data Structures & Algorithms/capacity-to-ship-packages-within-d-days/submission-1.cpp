class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left {1};
        int right {accumulate(weights.begin(), weights.end(), 0)};

        while (left <= right) {
           int mid = left + (right - left) / 2;
           if (check(mid, days, weights)) {
            right = mid - 1;
           } else {
            left = mid + 1;
           }
        }

        return left;
    }

    bool check(int maxWeight, int days, vector<int>& weights) {
        int count {1};
        int total {0};

        for (const auto& weight: weights) {
            if (weight > maxWeight) {
                return false;
            }
            if (weight + total <= maxWeight) {
                total += weight;
            } else {
                total = weight;
                ++count;
            }
        }

        return count <= days;
    }
};