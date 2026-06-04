class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;

        for (int i = 0; i <= n; ++i) {
            int ones{0};
            int num {i};
            while (num > 0) {
                ones++;
                num &= num - 1;
            }
            output.push_back(ones);
        }

        return output;
    }
};
