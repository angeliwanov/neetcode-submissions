class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto word: wordDict) {
            dict.insert(word);
        }
        vector<string> res;
        vector<string> words;
        backtrack(0, s, dict, res, "", words, 0);
        return res;
    }

    void backtrack(int index, string s, unordered_set<string>& dict, vector<string>& res, string word, vector<string>& words, int chars) {        
        if (index == s.size()) {
            if (chars == s.size()) {
                string sen;
                for (size_t i = 0; i < words.size(); ++i) {
                    sen += words[i];
                    if (i != words.size()-1) {
                        sen += " ";
                    }
                }
                res.push_back(sen);
            }
            return;
        }

        word += s[index];        
        if (dict.contains(word)) {
            words.push_back(word);                        
            backtrack(index + 1, s, dict, res, "", words, chars + word.size());            
            words.pop_back();
        }
        backtrack(index + 1, s, dict, res, word, words, chars);
    }
};