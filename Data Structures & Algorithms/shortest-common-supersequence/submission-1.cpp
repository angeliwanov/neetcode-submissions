class Solution {
   public:
    string shortestCommonSupersequence(string str1, string str2) {
        size_t len1 = str1.size();
        size_t len2 = str2.size();
        vector<vector<string>> dp(len1 + 1, vector<string>(len2 + 1));

        for (int i = 0; i < len1+1; i++) {
            for (int j = 0; j < len2+1; j++) {
                if (i == 0) {
                    dp[i][j] = str2.substr(0,j);
                } else if (j == 0) {
                    dp[i][j] = str1.substr(0,i);
                } else if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + str1[i-1];
                } else {
                    if (dp[i][j-1].size() < dp[i-1][j].size()) {
                        dp[i][j] = dp[i][j-1] + str2[j-1];
                    } else {
                        dp[i][j] = dp[i-1][j] + str1[i-1];
                    }
                }
            }
        }

        return dp[len1][len2];   
    }
};