class KthLargest {
private:
    int maxSize {0};
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        for (const auto& num: nums) {
            minHeap.push(num);        
        }
        while (minHeap.size() > maxSize) {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > maxSize){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
