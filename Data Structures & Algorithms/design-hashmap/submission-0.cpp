class MyHashMap {
   private:
    struct ListNode {
        int key;
        int value;
        ListNode* next;
        ListNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    vector<ListNode*> hashmap;
    int hash(int key) { return key % hashmap.size(); }

   public:
    MyHashMap() {
        hashmap.resize(10000);
        for (auto& bucket : hashmap) {
            bucket = new ListNode(-1,-1);
        }
    }

    void put(int key, int value) {
        ListNode* curr = hashmap[hash(key)];        
        while (curr->next != nullptr) {
            if (curr->next->key == key) {
                curr->next->value = value;
                return;
            } 
            curr = curr->next;
        }
        curr->next = new ListNode(key, value);
    }

    int get(int key) {
        ListNode* curr = hashmap[hash(key)];
        while (curr->next != nullptr) {
            if (curr->next->key == key) {               
                return curr->next->value;
            } 
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key) {
        ListNode* curr = hashmap[hash(key)];
        while (curr->next != nullptr) {
            if (curr->next->key == key) {
                curr->next = curr->next->next;
                return;
            } 
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */