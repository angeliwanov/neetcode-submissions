class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> directions {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> que;
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 2) {
                    que.emplace(row,col);                    
                } else if (grid[row][col] == 1) {
                    ++fresh;
                }
            }
        }

        int minutes = 0;

        while (!que.empty() && fresh) {
            int length = que.size();

            for (; length > 0; --length) {
                auto [row, col] = que.front();
                que.pop();                

                for (auto [dRow, dCol]: directions) {
                    int nRow = row + dRow;
                    int nCol = col + dCol;                    
                    if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && grid[nRow][nCol] == 1) {
                        grid[nRow][nCol] = 2;
                        fresh--;
                        que.emplace(nRow,nCol);
                    }
                }
            }

            ++minutes;
        }
        
        return fresh ? -1 : minutes;
    }
};
