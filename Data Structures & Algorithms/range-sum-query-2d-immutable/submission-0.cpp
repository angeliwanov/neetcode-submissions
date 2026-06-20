class NumMatrix {
    std::vector<std::vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();

        for (size_t row = 0; row < rows; ++row) {
            std::vector<int> curr(cols+1);            
            
            for (size_t col = 0; col < cols; ++ col) {
                curr[col+1] = curr[col] + matrix[row][col];
            }

            prefix.push_back(curr);
        }    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum{0};

        for (size_t row = row1; row <= row2; ++row) {
            sum += prefix[row][col2+1] - prefix[row][col1];
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */