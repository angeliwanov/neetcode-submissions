class MinStack {
private:
    std::stack<int> stk;
    std::stack<int> minStk;

public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        val = std::min(val, minStk.empty() ? val : minStk.top());
        minStk.push(val);
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
        
    }
    
    int getMin() {
        return minStk.top();
    }
};
