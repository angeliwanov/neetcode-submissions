class Solution {
private:
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        for (int r = 0; r < heights.size(); ++r) {
            for (int c = 0; c < heights[0].size(); ++c) {
                unordered_set<int> visited;
                if (dfs(heights,r,c,visited) == 3) {
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& heights, int r, int c, unordered_set<int>& visited) {
        visited.insert(r*heights[0].size()+c);
        int ocean {0};
        if (r == 0 || c == 0) {
            ocean |= 1;
        }
        if (r == heights.size() - 1 || c == heights[0].size() - 1) {
            ocean |= 2;
        }

        for (auto& [x,y] : directions) {
            int nr {r + x};
            int nc {c + y};
            if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && heights[nr][nc] <= heights[r][c] && visited.find(nr*heights[0].size()+nc) == visited.end()) {
                ocean |= dfs(heights,nr,nc,visited);
            }
        }
        return ocean;
    }
};
