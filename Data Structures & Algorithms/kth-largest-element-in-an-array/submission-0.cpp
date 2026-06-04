class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::greater<int>> minHeap;
        for (const auto& num: nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
