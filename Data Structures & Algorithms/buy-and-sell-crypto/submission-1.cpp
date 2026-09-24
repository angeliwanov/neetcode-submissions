class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left {0};
        int profit {0};

        for (int right = 1; right < prices.size(); ++right) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            profit = max(profit, prices[right] - prices[left]);
        }

        return profit;
    }
};
