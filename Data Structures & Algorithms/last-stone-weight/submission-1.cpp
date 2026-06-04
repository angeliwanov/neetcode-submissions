class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap (stones.begin(), stones.end());                

        while (maxHeap.size() > 1) {
            auto stone1 = maxHeap.top();
            maxHeap.pop();
            auto stone2 = maxHeap.top();
            maxHeap.pop();
            if (stone1 != stone2) {
                maxHeap.push(stone1-stone2);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
