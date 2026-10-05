
class MyCircularQueue {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v, ListNode* n = nullptr): val(v), next(n) {}
    };
    int count {0};
    int capacity {0};
    ListNode* front = new ListNode(-1);
    ListNode* rear = front;

public:
    MyCircularQueue(int k) {
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        if (isEmpty()) {
            rear->val = value;
            ++count;
            return true;
        } else {
            rear->next = new ListNode(value);
            rear = rear->next;
            ++count;
            return true;
        }       
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front->val = -1;
        --count;
        if (!isEmpty()) {
            ListNode* toDelete = front;
            front = front->next;
            toDelete->next = nullptr;
            delete toDelete;
        }
        return true;
    }
    
    int Front() {
        return front->val;
    }
    
    int Rear() {
        return rear->val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */