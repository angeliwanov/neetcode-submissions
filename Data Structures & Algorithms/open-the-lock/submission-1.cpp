class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        vector<int> move = {-1,1};
        for (const auto& deadend: deadends) {
            visited.insert(deadend);
        }        
        queue<string> q;
        if (visited.find("0000") == visited.end()) {
            visited.insert("0000");
            q.push("0000");
        }
        int moves{0};

        while (!q.empty()) {
            size_t length {q.size()};
            for (size_t i = 0; i < length; ++i) {
                string comb = q.front();
                q.pop();
                if (comb == target) {
                    return moves;
                }
                for (int digit = 0; digit < 4; ++digit) {
                    for (const auto& m: move) {
                        string lock = comb.substr(0, digit) + char('0' + (comb[digit] - '0' + m + 10) % 10) + comb.substr(digit + 1);
                        if (visited.find(lock) == visited.end()) {
                            visited.insert(lock);
                            q.push(lock);
                        }
                    }
                }
            }
            ++moves;
        }

        return -1;
    }
};