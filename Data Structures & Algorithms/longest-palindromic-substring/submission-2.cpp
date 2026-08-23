class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        int resLen{0};

        for (int i = 0; i < s.size(); ++i) {
            // odd
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > resLen) {
                    resLen = right - left + 1;
                    result = s.substr(left, resLen);
                }
                --left;
                ++right;
            }

            // even
            left = i;
            right = i+1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > resLen) {
                    resLen = right - left + 1;
                    result = s.substr(left, resLen);
                }
                --left;
                ++right;
            }
        }

        return result;
    }
};
