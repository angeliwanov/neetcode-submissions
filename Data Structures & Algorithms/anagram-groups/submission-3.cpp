class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> words;

        for (const auto& str: strs) {
            vector<int> count (26,0);
            for (char ch: str) {
                count[ch - 'a'] += 1;
            }
            string key;
            for (int c: count) {
                key += to_string(c) + ',';
            }            
            words[key].push_back(str);

        }

        vector<vector<string>> res;
        for (const auto& [_, values] : words) {
            res.push_back(values);
        }
        return res;
    }
};
