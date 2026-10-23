class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> substr;
        backtrack(res, substr, s, 0);
        return res;
    }

    bool isPalindrome(string word) {
        int l = 0;
        int r = static_cast<int>(word.size()) - 1;
        while (l < r) {
            if (word[l++] != word[r--]) {
                return false;
            }
        }
        return true;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& substr, string s, size_t index) {
        if (index == s.size()) {
            res.emplace_back(substr);
            return;
        }

        for (size_t i = index; i < s.size(); ++i) {
            string word = s.substr(index, i-index+1);
            if (isPalindrome(word)) {
                substr.emplace_back(word);
                backtrack(res, substr, s, i+1);
                substr.pop_back();
            }
        }
    }
};
