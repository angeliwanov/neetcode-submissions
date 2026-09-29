class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto cmp = [](pair<int,int> p1, pair<int,int> p2) {return p1.first < p2.first;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq;
        vector<int> res;

        for (int i = 0; i < k-1; ++i) {
            pq.emplace(nums[i], i);
        }

        for (int i = k-1; i < nums.size(); ++i) {
            pq.emplace(nums[i], i);
            while (pq.top().second < i - k + 1) {
                pq.pop();
            }
            res.emplace_back(pq.top().first);
        }

        return res;

    }
};
