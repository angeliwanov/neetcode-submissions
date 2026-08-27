class MyHashSet {
   private:
    struct ListNode {
        int key;
        ListNode* next;
        ListNode(int k) : key(k), next(nullptr) {}
   };
   vector<ListNode*> hashset;    
   int hash(int key) {
    return key % hashset.size();
   }

   public :
       MyHashSet() {
        hashset.resize(10000);
        for (auto& bucket: hashset) {
            bucket = new ListNode(0);
        }
    }

    void add(int key) {
        ListNode* curr = hashset[hash(key)];
        while (curr->next != nullptr) {
            if (curr->next->key == key) {                
                return;
            } 
            curr = curr->next;
        }
        curr->next = new ListNode(key);
    }

    void remove(int key) {
        ListNode* curr = hashset[hash(key)];
        while (curr->next != nullptr) {
            if (curr->next->key == key) {
                curr->next = curr->next->next;
                return;
            } 
            curr = curr->next;
        }        
    }

    bool contains(int key) {
        ListNode* curr = hashset[hash(key)];
        while (curr->next != nullptr) {
            if (curr->next->key == key) {                
                return true;
            } 
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */