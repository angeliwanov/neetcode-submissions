class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int maxLen{0};
        size_t left {0};
        for (size_t right = 0; right < s.size(); ++right) {            
            while (chars.find(s[right]) != chars.end()) {
                chars.erase(s[left++]);
            }
            chars.insert(s[right]);
            maxLen = max(maxLen, static_cast<int>(right - left) + 1);
        }

        return maxLen;
    }
};
