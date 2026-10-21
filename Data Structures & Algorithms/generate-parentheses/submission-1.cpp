class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subset;
        backtrack(res, n, 0, subset, n);
        return res;
    }

    void backtrack(vector<string>& res, int opening, int closing, string& subset, int& n) {
        if (subset.size() == 2*n) {
            res.push_back(subset);
            return;
        }

        if (closing) {
            subset += ")";
            backtrack(res, opening, closing-1, subset, n);
            subset.pop_back();
        }

        if (opening) {
            subset += "(";
            backtrack(res, opening-1, closing+1, subset, n);
            subset.pop_back();
        }

    }
};
