class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> visited;
        for (auto &num : nums) {
            visited.insert(num);
        }

        int maxLen{0};
        for (auto &num : nums) {
            if (!visited.contains(num - 1)) {
                int length = 1;
                while (visited.contains(num + length)) {
                    ++length;
                }
                maxLen = std::max(maxLen, length);
            }
        }

        return maxLen;
    }
};
