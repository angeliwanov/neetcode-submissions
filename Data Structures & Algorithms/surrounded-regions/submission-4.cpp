class Solution {
private:
    vector<pair<int,int>> directions {{0,1},{0,-1},{1,0},{-1,0}};

public:
    void solve(vector<vector<char>>& board) {       
        unordered_set<int> visited;        
        vector<int> firstLastCol = {0, static_cast<int>(board[0].size()) - 1};
        for (int row = 0; row < board.size(); ++row) {
            for (const auto& col : firstLastCol) {
                if (board[row][col] == 'O' and visited.find(row*board[0].size()+col) == visited.end()) {
                    dfs(row, col, board, visited);
                }
            }
        }

        vector<int> firstLastRow = {0, static_cast<int>(board.size()) - 1};
        for (const auto& row : firstLastRow) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == 'O' and visited.find(row*board[0].size()+col) == visited.end()) {
                    dfs(row, col, board, visited);
                }
            }
        }

        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == 'O' and visited.find(row*board[0].size()+col) == visited.end()) {
                    board[row][col] = 'X';
                }
            }
        }
    }

    void dfs(int row, int col, vector<vector<char>>& board, unordered_set<int>& visited) {
        visited.insert(row*board[0].size() + col);
        for (const auto& [x,y] : directions) {
            int nr {row + x};
            int nc {col + y};
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] == 'O' && visited.find(nr*board[0].size()+nc) == visited.end()) {
                dfs(nr,nc,board,visited);
            }
        }
    }
};
