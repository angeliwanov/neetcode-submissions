class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board.size();
        unordered_map<int, unordered_set<char>> r;   
        unordered_map<int, unordered_set<char>> c;   
        unordered_map<int, unordered_set<char>> b;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                const auto& digit = board[row][col];
                if (digit == '.') {
                    continue;
                }
                int box = (row/3)*10 + (col/3);
                if (r[row].contains(digit) || c[col].contains(digit) || b[box].contains(digit)) {
                    return false;
                }
                r[row].insert(digit);
                c[col].insert(digit);
                b[box].insert(digit);
            }
        }

        return true;
    }
};
