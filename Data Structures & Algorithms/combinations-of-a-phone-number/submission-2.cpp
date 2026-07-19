class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        std::vector<std::string> result;
        std::vector<std::string> digToChar{"",    "",    "abc",  "def", "ghi",
                                           "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backtrack(result, "", 0, digits, digToChar);
        return result;
    }

    static void backtrack(std::vector<std::string>& result, const std::string& comb, size_t pos,
                          const std::string& digits, std::vector<std::string> digToChar) {
        if (comb.size() == digits.size()) {
            result.push_back(comb);
            return;
        }

        auto chars = digToChar[static_cast<size_t>(digits[pos] - '0')];
        for (char chr : chars) {
            backtrack(result, comb + chr, pos + 1, digits, digToChar);
        }
    }
};
