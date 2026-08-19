class Solution {
public:
    int numDistinct(string s, string t) {
        size_t sLen = s.size();
        size_t tLen = t.size();
        std::vector<std::vector<int>> dp ((tLen+1), std::vector<int> (sLen+1));
        dp[0] = std::vector<int> (sLen+1, 1);

        for (size_t i = 1; i < tLen + 1; ++i) {
            for (size_t j = 1; j < sLen + 1; ++j) {
                dp[i][j] = dp[i][j-1];
                if (s[j-1] == t[i-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }                
            }            
        }

        return dp[tLen][sLen];

    }
};
