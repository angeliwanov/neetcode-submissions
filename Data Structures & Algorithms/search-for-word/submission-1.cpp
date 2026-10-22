class Solution {
private:
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_set<int> visited;
        string s;
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                visited.insert({r*10+c});
                s += board[r][c];
                if (backtrack(r,c,s,visited,word,board)){
                    return true;
                }
                s.pop_back();
                visited.erase({r*10+c});
            }
        }
        return false;
    }

    bool backtrack(int r, int c, string s, unordered_set<int> visited, string word, vector<vector<char>>& board) {        
        if (s.size() == word.size()) {
            return s == word;
        }

        for (auto& [x,y] : directions) {
            int nr = r + x;
            int nc = c + y;
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                if (!visited.contains({nr*10+nc})) {
                    visited.insert({nr*10+nc});
                    s += board[nr][nc];
                    if (backtrack(nr,nc,s,visited,word,board)) {
                        return true;
                    }
                    s.pop_back();
                    visited.erase({nr*10+nc});
                }
            }
        }
        return false;
    }
};
