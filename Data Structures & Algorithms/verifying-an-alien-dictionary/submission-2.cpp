class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> orderIdx;
        for (size_t i = 0; i < order.size(); ++i) {
            orderIdx[order[i]] = static_cast<int>(i);
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
                    if (orderIdx[w1[j]] < orderIdx[w2[j]]) {
                        break;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};