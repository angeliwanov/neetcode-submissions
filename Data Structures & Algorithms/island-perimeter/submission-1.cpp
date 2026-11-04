class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<pair<int,int>> directions {{0,1},{0,-1},{1,0},{-1,0}};
        stack<pair<int,int>> stk;
        unordered_set<int> visited;
        for (size_t r = 0; r < grid.size(); ++r) {
            for (size_t c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    stk.push({r,c});
                    visited.insert(r*10+c);
                }
            }
        }

        int area {0};
        while (!stk.empty()) {
            auto p = stk.top();
            stk.pop();
            area += 4;

            for (const auto& dir: directions) {
                int nr {p.first + dir.first};
                int nc {p.second + dir.second};
                if (nr >= 0 and nr < grid.size() and nc >= 0 and nc < grid[0].size() and grid[nr][nc] == 1) {
                    area-=1;
                    if (visited.find(nr*10+nc) == visited.end()) {
                        stk.push({nr,nc});
                        visited.insert(nr*10+nc);
                    }
                }
            }
        }

        return area;
    }

    
};