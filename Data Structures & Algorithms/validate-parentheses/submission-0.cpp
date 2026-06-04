class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> stk;
        std::unordered_map<char, char> pairs = {{')','('},{'}','{'},{']','['}};

        for (char c: s) {
            if (pairs.contains(c)) {
                if (stk.empty() || stk.back() != pairs.at(c)) {
                    return false;
                }
                stk.pop_back();                
            } else {
                stk.push_back(c);
            }
        }

        return stk.empty();
    }
};
