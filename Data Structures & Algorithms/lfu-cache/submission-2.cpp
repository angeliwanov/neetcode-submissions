class LFUCache {
    struct ListNode {
        int key;
        int useCount;
        ListNode* next;
        ListNode* prev;
        ListNode(int k, int u, ListNode* n = nullptr, ListNode* p = nullptr)
            : key(k), useCount(u), next(n), prev(p) {}
    };

   private:
    int capacity{0};
    ListNode* head = new ListNode(-1, -1);
    ListNode* tail = new ListNode(-1, -1);
    unordered_map<int, int> cache;

   public:
    LFUCache(int capacity) : capacity(capacity) {        
        head->next = tail;
        tail->prev = head;
    }

    ~LFUCache() {
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    int get(int key) {
        // check if present in cache
        if (!cache.contains(key)) {
            return -1;
        }
        // find it and increase useCount
        ListNode* curr = head->next;
        while (curr->key != key) {   
            curr = curr->next;         
        }
        ++curr->useCount;
        // detach it from its current position
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        // search for insertion point
        ListNode* insert = curr->next;
        while (insert->useCount != -1 && insert->useCount <= curr->useCount) {
            insert = insert->next;
        }
        // insert it
        curr->next = insert;
        curr->prev = insert->prev;
        insert->prev->next = curr;
        insert->prev = curr;
        return cache[key];
    }

    void put(int key, int value) {
        // remove lfu/lru if cache is full and inserting new node
        if (static_cast<int>(cache.size()) == capacity && !cache.contains(key)) {
            ListNode* toDelete = head->next;
            head->next = toDelete->next;
            toDelete->next->prev = head;
            cache.erase(toDelete->key);
            delete toDelete;
        }
        ListNode* newNode;
        // create new node if not existing
        if (!cache.contains(key)) {
            newNode = new ListNode(key, 1);
        } else {
        // find the node if key already present
            ListNode* curr = head->next;
            while (curr->key != key) {               
                curr = curr->next;
            }
            newNode = curr;
            ++newNode->useCount;
            //detach it
            newNode->prev->next = newNode->next;
            newNode->next->prev = newNode->prev;                    
        }
        // update cache
        cache[key] = value;
        // search for insertion point
        ListNode* insert = head->next;
        while (insert->useCount != -1 && insert->useCount <= newNode->useCount) {
            insert = insert->next;            
        }
        // insert it
        newNode->next = insert;        
        newNode->prev = insert->prev;
        insert->prev->next = newNode;
        insert->prev = newNode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */