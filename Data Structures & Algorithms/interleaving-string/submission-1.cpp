class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t len1 = s1.size();
        size_t len2 = s2.size();
        if (len1+len2 != s3.size()) {
            return false;
        }

        std::vector<std::vector<bool>> dp (len1+1, std::vector<bool> (len2+2, false));
        dp[len1][len2] = true;

        for (int i = len1; i >= 0; --i) {
            for (int j = len2; j >= 0; --j) {
                if (i < len1 and s1[i] == s3[i+j]) {
                    dp[i][j] = dp[i+1][j];
                }
                if (j < len2 and s2[j] == s3[i+j]) {
                    dp[i][j] = dp[i][j+1];
                }                
            }
        }

        return dp[0][0];
    }
};
