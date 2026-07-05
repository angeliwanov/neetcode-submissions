class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {        
        size_t n = accounts.size();
        vector<int> parent(n);
        vector<int> rank(n);
        for (size_t i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }

        unordered_map<string, int> emails;  
        for (size_t i = 0; i < accounts.size(); ++i) {
            auto account = accounts[i];
            for (size_t j = 1; j < account.size(); ++j) {
                string email = account[j];
                if (emails.contains(email)) {
                    unionNodes(parent, rank, i, emails[email]);                    
                } else {
                    emails[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> groups;
        for (auto& [email, i] : emails) {
            int leader = findParent(parent, i);
            groups[leader].push_back(email);
        }

        vector<vector<string>> result;
        for (auto& [i, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[i][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            result.push_back(merged);
        }
        return result;

    }

    int findParent(vector<int>& parent, int n) {
        int p = parent[n];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool unionNodes(vector<int>& parent, vector<int>& rank, int n1, int n2) {
        int p1 = findParent(parent, n1);
        int p2 = findParent(parent, n2);

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
};