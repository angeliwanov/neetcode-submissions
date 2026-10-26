class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antidiags;
        vector<vector<string>> res;
        vector<vector<char>> board;
        for (int i = 0; i < n; ++i) {
            vector<char> row;
            for (int j = 0; j < n; ++j) {
                row.push_back('.');
            }
            board.push_back(row);
        }        
        backtrack(0, cols, diags, antidiags, res, board, n);
        return res;
    }

    void backtrack(int row, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antidiags, vector<vector<string>>& res, vector<vector<char>>& board, int& n) {
        if (row == n) {
            vector<string> b;
            for (auto& r : board) {
                b.push_back(string (r.begin(), r.end()));
            }
            res.push_back(b);
        }

        for (int col = 0; col < n; ++col) {
            int diag {row - col};
            int antidiag = {row + col};
            if (cols.contains(col) || diags.contains(diag) || antidiags.contains(antidiag)) {
                continue;
            }
            cols.insert(col);
            diags.insert(diag);
            antidiags.insert(antidiag);
            board[row][col] = 'Q';
            backtrack(row+1, cols, diags, antidiags, res, board, n);
            board[row][col] = '.';
            antidiags.erase(antidiag);
            diags.erase(diag);
            cols.erase(col);
        }
    }
};
