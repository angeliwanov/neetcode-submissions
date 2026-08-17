class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp (n+1, INT_MAX);
        vector<int> duration {1,7,30};
        dp[n] = 0;

        for (int i = n-1; i >= 0; --i) {            
            int k = i;
            for (int j = 0; j < 3; ++j) {
                int cost = costs[j];
                int dur = duration[j];
                while (k < n && days[k] < days[i] + dur) {
                    ++k;
                }
                dp[i] = min(dp[i], dp[k] + cost);
            }
        }

        return dp[0];
    }
};