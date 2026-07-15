class MedianFinder {
   private:
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    std::priority_queue<int, std::vector<int>, std::less<>> maxHeap;

   public:
    MedianFinder() {}

    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if (maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        }
        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};
