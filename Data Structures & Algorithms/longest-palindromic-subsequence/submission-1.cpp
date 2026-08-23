class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r = string(s.rbegin(), s.rend());        
        vector<vector<int>> dp (s.size() + 1, vector<int> (r.size()+1));

        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = r.size() - 1; j >= 0; --j) {
                if (s[i] == r[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};