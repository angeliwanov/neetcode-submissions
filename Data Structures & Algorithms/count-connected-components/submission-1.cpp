class Solution {
   public:
    static bool Union(std::vector<size_t>& parent, std::vector<int>& rank, size_t n1, size_t n2) {
        size_t p1 = find(parent, n1);
        size_t p2 = find(parent, n2);

        if (p1 == p2) {
            return false;
        }

        if (rank[p1] > rank[p2]) {
            rank[p1] += rank[p2];
            parent[p2] = p1;
        } else {
            rank[p2] += rank[p1];
            parent[p1] = p2;
        }
        return true;
    }

    static size_t find(std::vector<size_t>& parent, size_t n) {
        size_t p = parent[n];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<size_t> parent(n);
        std::vector<int> rank(n);

        for (size_t i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }

        int components = n;
        for (auto edge : edges) {
            if (Union(parent, rank, edge[0], edge[1])) {
                --components;
            }
        }
        return components;
    }
};
