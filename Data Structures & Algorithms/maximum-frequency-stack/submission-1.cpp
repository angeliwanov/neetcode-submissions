class FreqStack {
private:
    int idx{0};
    priority_queue<vector<int>> pq;
    unordered_map<int, int> count;

public:
    FreqStack() {
        
    }
    
    void push(int val) {
        ++count[val];
        pq.push({count[val], idx++, val});
    }
    
    int pop() {
        auto top = pq.top();
        pq.pop();
        int val= top[2];
        --count[val];
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */