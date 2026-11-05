class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> graph;
        for (size_t i = 1; i < order.size(); ++i) {
            graph[order[i-1]] = order[i];
        }

        for (size_t i = 1; i < words.size(); ++i) {
            string w1 = words[i-1];
            string w2 = words[i];
            size_t minLen = min(w1.size(), w2.size());
            if (w1.substr(0, minLen) == w2.substr(0, minLen) && w1.size() > w2.size()) {
                return false;
            }
            for (size_t j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    if (dfs(graph, w1[j], w2[j])) {
                        break;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool dfs(unordered_map<char,char>& graph, char ch1, char ch2) {
        if (graph.find(ch1) == graph.end()) {
            return false;
        }
        if (graph[ch1] == ch2) {
            return true;
        }
        return dfs(graph, graph[ch1], ch2);
    }
};