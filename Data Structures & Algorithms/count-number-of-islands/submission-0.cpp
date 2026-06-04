class Solution {
    private:
        inline static const vector<tuple<int, int>> directions {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int rows, int cols) {
        for (auto [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == '1') {
                grid[newRow][newCol] = '0';
                dfs(grid, newRow, newCol, rows, cols);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands {0};
        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '1') {
                    ++islands;
                    grid[row][col] = '0';
                    dfs(grid, row, col, rows, cols);
                }
            }
        }

        return islands;   
    }
};
