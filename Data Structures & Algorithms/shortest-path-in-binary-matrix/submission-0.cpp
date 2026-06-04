class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
                std::vector<std::pair<int, int>> directions{{0, 1},   {0, -1}, {1, 0},  {-1, 0},
                                                    {-1, -1}, {1, 1},  {-1, 1}, {1, -1}};
        std::queue<std::pair<int, int>> que;
        int rows = grid.size();
        int cols = grid[0].size();

        if (grid[rows-1][cols-1] == 1) {
            return -1;
        }

        if (grid[0][0] == 0) {
            que.emplace(0, 0);
            grid[0][0] = 1;          
        }

        int path = 0;
        while (!que.empty()) {
            ++path; 
            int length = que.size();
            
            while (length) {
                --length;
                auto [row, col] = que.front();                
                que.pop();

                if (row == rows - 1 && col == cols - 1) {
                    return path;
                }

                for (auto [dRow, dCol] : directions) {
                    int newRow = row + dRow;
                    int newCol = col + dCol;

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 0) {
                        grid[newRow][newCol] = 1;
                        que.emplace(newRow, newCol);
                    }
                }
            }
        }

        return -1;
    }
};