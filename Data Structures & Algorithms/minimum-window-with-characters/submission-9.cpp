class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        int left {0};
        vector<int> res = {0,0};

        for (const auto& ch: t) {
            ++count[ch];
        }

        for (size_t right = 0; right < s.size(); ++right) {            
            if (count.contains(s[right])) {
                --count[s[right]];
            }
            while (!hasPositive(count)) {
                if (res[1] == 0 || right - left + 1 < res[1]) {
                    res[0] = left;
                    res[1] = right-left+1;
                }
                if (count.contains(s[left])) {
                    ++count[s[left]];
                }
                ++left;
            }

        }

        return s.substr(res[0], res[1]);
    }

    bool hasPositive(unordered_map<char, int>& count) {
        for (const auto& el : count) {            
            if (el.second > 0) {
                return true;
            }
        }
        return false;
    }
};
