class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incoming (n, 0);
        vector<int> outgoing (n, 0);

        for (const auto& t: trust) {
            incoming[t[1]-1] += 1;
            outgoing[t[0]-1] += 1;
        }

        for (int i = 0; i < n; ++i) {
            if (incoming[i] == n-1 && outgoing[i] == 0) {
                return i+1;
            }
        }

        return -1;
    }
};