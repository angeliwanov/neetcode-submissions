class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<size_t, int> cache;
        unordered_set<string> words;
        for (string& word : dictionary) {
            words.insert(word);
        }

        return dp(0, s, words, cache);
    }

    int dp(size_t i, string s, unordered_set<string>& words, unordered_map<size_t, int>& cache) {
        if (i == s.size()) {
            return 0;
        }
        if (cache.contains(i)) {
            return cache[i];
        }
        int ans = 1 + dp(i+1, s, words, cache);
        for (size_t j = i; j < s.size(); ++j) {
            if (words.contains(s.substr(i, j-i+1))) {
                ans = min(ans, dp(j+1, s, words, cache));
            }
        }

        cache[i] = ans;
        return ans;
    }
};