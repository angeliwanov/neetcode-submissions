class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;
        for (const auto& word: wordList) {
            for (size_t i = 0; i < word.size(); ++i) {
                string dw = word + word;                
                graph[dw.substr(i, word.size()-1)].emplace_back(word);
            }
        }

        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);

        int steps{0};
        while (!q.empty()) {
            ++steps;
            size_t len = q.size();
            for (size_t i = 0; i < len; ++i) {
                string word = q.front();
                if (word == endWord) {
                    return steps;
                }
                q.pop();
                for (size_t i = 0; i < word.size(); ++i) {
                    string dw = word + word;
                    for (const auto& nei: graph[dw.substr(i, word.size()-1)]) {
                        if (visited.find(nei) == visited.end()) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }
        }

        return 0;
    }
};
