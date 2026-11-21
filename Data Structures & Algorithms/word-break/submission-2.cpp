class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> found;
        found.emplace_back(0);
        unordered_set<string> words;
        for (const auto& word: wordDict) {
            words.insert(word);
        }

        for (size_t i = 1; i < s.size() + 1; ++i) {
            string curr = s.substr(0, i);
            size_t length = found.size();
            for (size_t j = 0; j < length; ++j) {
                int f = found[j];
                string word = curr.substr(f);
                if (words.find(word) != words.end()) {
                    if (i == s.size()) {
                        return true;
                    }
                    found.emplace_back(curr.size());
                    break;
                }
            }
        }

        return false;
    }
};
