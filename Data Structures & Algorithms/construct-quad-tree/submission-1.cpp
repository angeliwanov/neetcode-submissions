/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int zeros{countDigit(grid, 0)};
        int ones{countDigit(grid, 1)};

        if (zeros and not ones) {
            return new Node(0, true);
        }
        if (ones and not zeros) {
            return new Node(1, true);
        }

        Node* node = new Node();
        int n {static_cast<int>(grid.size()) / 2};
        vector<vector<int>> tl (n); 
        buildGrid(grid, 0, n, 0, n, tl);        
        vector<vector<int>> tr (n);
        buildGrid(grid, 0, n, n, n*2, tr);  
        vector<vector<int>> bl (n);
        buildGrid(grid, n, n*2, 0, n, bl);  
        vector<vector<int>> br (n);
        buildGrid(grid, n, n*2, n, n*2, br);  
        node->topLeft = construct(tl);
        node->topRight = construct(tr);
        node->bottomLeft = construct(bl);
        node->bottomRight = construct(br);

        return node;
    }

    int countDigit(vector<vector<int>>& grid, int digit) {
        int count{0};
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == digit) {
                    ++count;
                }
            }
        }
        return count;
    }

    void buildGrid(vector<vector<int>>& oldGrid, int rs, int re, int cs, int ce, vector<vector<int>>& newGrid) {
        int c {-1};
        for (int i = rs; i < re; ++i) {
            ++c;
            for (int j = cs; j < ce; ++j) {
                newGrid[c].push_back(oldGrid[i][j]);                
            }
        }
    }
};