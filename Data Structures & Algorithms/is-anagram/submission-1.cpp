class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, int> charCount{};

        for (size_t i = 0; i < s.size(); ++i) {
            charCount[s[i]]++;
            charCount[t[i]]--;
        }

        for (auto &[_, count]: charCount) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
