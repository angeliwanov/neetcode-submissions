class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> chars;
        int maxLen{0};
        int maxFreq{0};
        size_t left{0};

        for (size_t right = 0; right < s.size(); ++right) {
            ++chars[s[right]];
            maxFreq = max(maxFreq, chars[s[right]]);
            while ((right - left + 1) - maxFreq > k) {
                --chars[s[left++]];
            }
            maxLen = max(maxLen, static_cast<int>(right - left) + 1);
        }   
        return maxLen;
    }
};
