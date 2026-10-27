class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antidiags;
        return backtrack(0, cols, diags, antidiags, n);
    }

    int backtrack(int row, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antidiags, int& n) {
        if (row == n) {
            return 1;
        }

        int solutions {0};

        for (int col = 0; col < n; ++col) {
            int diag {row - col};
            int antidiag {row + col};
            if (cols.contains(col) || diags.contains(diag) || antidiags.contains(antidiag)) {
                continue;
            }
            cols.insert(col);
            diags.insert(diag);
            antidiags.insert(antidiag);
            solutions += backtrack(row + 1, cols, diags, antidiags, n);
            cols.erase(col);
            diags.erase(diag);
            antidiags.erase(antidiag);
        }

        return solutions;
    }
};