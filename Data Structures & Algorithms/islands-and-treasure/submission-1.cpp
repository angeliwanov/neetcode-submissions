class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int inf {2147483647};
        vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (size_t row = 0; row < grid.size(); ++row) {
            for (size_t col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 0) {
                    q.push({row,col});
                }
            }
        }

        while (!q.empty()) {
            size_t length = q.size();
            for (size_t i = 0; i < length; ++i) {
                auto [r,c] = q.front();
                q.pop();
                for (auto& [x,y] : directions) {
                    int nr = r + x;
                    int nc = c + y;
                    if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == inf) {
                        grid[nr][nc] = 1 + grid[r][c];
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};
