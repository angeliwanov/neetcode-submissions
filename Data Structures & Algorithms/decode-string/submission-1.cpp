class Solution {
public:
    string decodeString(string s) {
        vector<char> res;

        for (const auto& c : s) {
            if (c == ']') {
                string decoded = "";
                while (!res.empty() && res.back() != '[') {
                    decoded = res.back() + decoded;
                    res.pop_back();
                }
                res.pop_back();
                string repeat = "";
                while (!res.empty() && std::isdigit(res.back())) {
                    repeat = res.back() + repeat;
                    res.pop_back();
                }
                for (int i = 0; i < std::stoi(repeat); ++i) {
                    for (const auto& d: decoded) {
                        res.emplace_back(d);
                    }
                }
            } else {
                res.emplace_back(c);
            }
        }

        std::string str(res.begin(), res.end());
        return str;
    }
};