class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        std::stack<std::tuple<int, int>> stk;        
        std::vector<tuple<int, int>> directions {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int rows = image.size();
        int cols = image[0].size();

        int start = image[sr][sc];
        if (start != color) {
            stk.push({sr, sc});       
            image[sr][sc] = color;     
        }

        while (!stk.empty()) {
            auto [row, col] = stk.top();            
            stk.pop();

            for (auto [x, y]: directions) {
                int newRow = row + x;
                int newCol = col + y;
                if (0 <= newRow && newRow < rows && 0 <= newCol && newCol < cols && image[newRow][newCol] == start) {                    
                    stk.push({newRow, newCol});
                    image[newRow][newCol] = color;
                }
            }
        }

        return image;
    }
};