class Solution {
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        size_t n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1);

        for (size_t i = 1; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (auto& edge : edges) {
            if (!uni(parent, rank, edge[0], edge[1])) {
                return edge;
            }
        }
        
    }

    int find(vector<int>& parent, int n) {
        int p = parent[n];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    };

    bool uni(vector<int>& parent, vector<int>& rank, int n1, int n2) {
        int p1 = find(parent, n1);
        int p2 = find(parent, n2);

        if (p1 == p2) {
            return false;
        }

        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];            
        }

        return true;
    };
};
