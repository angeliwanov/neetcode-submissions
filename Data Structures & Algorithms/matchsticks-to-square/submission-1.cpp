class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) {
            return false;
        }
        int total {accumulate(matchsticks.begin(), matchsticks.end(), 0)};
        if (total % 4 != 0) {
            return false;
        }
        int side {total / 4};
        if (*max_element(matchsticks.begin(), matchsticks.end()) > side) {
            return false;
        }
        vector<int> sides (3, 0);
        return backtrack(matchsticks, 0, sides, total, side);
    }

    bool backtrack(vector<int>& matchsticks, size_t index, vector<int>& sides, int& total, int& side) {
        if (index == matchsticks.size()) {
            return accumulate(sides.begin(), sides.end(), 0) == total * 3/4;
        }

        for (size_t i = index; i < matchsticks.size(); ++i) {
            if (i > index && matchsticks[i] == matchsticks[i-1]) {
                continue;
            }
            for (size_t j = 0; j < sides.size(); ++j) {
                if (sides[j] + matchsticks[i] <= side) {
                    sides[j] += matchsticks[i];
                    if (backtrack(matchsticks, i + 1, sides, total, side)) {
                        return true;
                    }
                    sides[j] -= matchsticks[i];
                }                
            }
        }

        return false;
    }
};