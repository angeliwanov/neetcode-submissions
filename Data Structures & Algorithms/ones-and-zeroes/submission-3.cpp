class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        std::vector<std::vector<int>> dp ((m+1), std::vector<int> (n+1));
        
        for (auto str : strs) {            
            int zeros = std::ranges::count(str, '0');
            int ones = std::ranges::count(str, '1');            
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = std::max(dp[i][j], 1+dp[i-zeros][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};