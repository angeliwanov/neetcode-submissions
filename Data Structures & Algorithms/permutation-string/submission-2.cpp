class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> c1;
        unordered_map<char, int> c2;

        for (const auto& ch : s1) {
            ++c1[ch];
        }

        for (size_t i = 0; i < s1.size(); ++i) {
            ++c2[s2[i]];
        }

        for (size_t i = s1.size(); i < s2.size(); ++i) {
            bool equal{true};
            for (auto p : c1) {
                if (c2[p.first] != p.second) {
                    equal = false;
                }
            }
            if (equal) {
                return true;
            }
            ++c2[s2[i]];
            --c2[s2[i - s1.size()]];
        }

        bool equal{true};
        for (auto p : c1) {
            if (c2[p.first] != p.second) {
                equal = false;
            }
        }
        return equal;
    }
};
