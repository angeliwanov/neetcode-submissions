class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions {{0,1},{0,-1},{1,0},{-1,0}};
        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());
        int maxArea = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    stack<pair<int,int>> stk;                    
                    stk.emplace(row,col);                    
                    grid[row][col] = 0;
                    int area = 1;
                    
                    while (!stk.empty()) {
                        auto [curRow, curCol] = stk.top();
                        stk.pop();                        

                        for (auto [dRow, dCol] : directions) {
                            int newRow = curRow + dRow;
                            int newCol = curCol + dCol;

                            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                                grid[newRow][newCol] = 0;
                                ++area;
                                stk.emplace(newRow, newCol);
                            }
                        }
                    }
                    
                    maxArea = max(maxArea, area);
                }

            }
        }

        return maxArea;
    }
};
