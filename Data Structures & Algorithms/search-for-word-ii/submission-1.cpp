class TrieNode {
public:
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    std::string word;
};


class Solution {
private:
    std::unique_ptr<TrieNode> root = std::make_unique<TrieNode>();
    std::vector<std::pair<int, int>> distances{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto &word : words) {
            TrieNode *node = root.get();
            for (auto chr : word) {
                if (!node->children.contains(chr)) {
                    node->children[chr] = std::make_unique<TrieNode>();
                }
                node = node->children[chr].get();
            }
            node->word = word;
        }

        std::vector<std::string> result;

        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                dfs(board, row, col, result, root.get());
            }
        }

        return result;
 
    }

    void dfs(std::vector<std::vector<char>> &board, int row, int col,
             std::vector<std::string> &result, TrieNode *node) {
        char chr = board[static_cast<size_t>(row)][static_cast<size_t>(col)];
        if (!node->children.contains(chr)) {
            return;
        }

        board[static_cast<size_t>(row)][static_cast<size_t>(col)] = '#';
        node = node->children[chr].get();

        if (node->word != "") {
            result.push_back(node->word);
            node->word = "";
        }

        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());

        for (auto [x, y] : distances) {
            int nRow = row + x;
            int nCol = col + y;
            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols &&
                board[static_cast<size_t>(nRow)][static_cast<size_t>(nCol)] != '#') {
                dfs(board, nRow, nCol, result, node);
            }
        }
        board[static_cast<size_t>(row)][static_cast<size_t>(col)] = chr;
    };
};
