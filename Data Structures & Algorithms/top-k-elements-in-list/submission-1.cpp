class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (const auto& num : nums) {
            ++count[num];
        }
        
        auto cmp = [](const pair<int,int>& p1, const pair<int,int>& p2) {
            return p1.second < p2.second;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> maxHeap;

        for (const auto& [key, value] : count) {
            maxHeap.emplace(key, value);
        }

        vector<int> res;
        while (!maxHeap.empty() && k > 0) {
            res.push_back(maxHeap.top().first);
            maxHeap.pop();
            --k;
        }

        return res;
    }
};
