class LRUCache {
private:
    std::unordered_map<int, pair<int, std::list<int>::iterator>> hashMap;
    std::list<int> order;
    int capacity = 0;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        if (hashMap.contains(key)) {            
            order.erase(hashMap[key].second);
            order.push_back(key);
            hashMap[key].second = std::prev(order.end());
            return hashMap[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (hashMap.contains(key)) {
            order.erase(hashMap[key].second);            
        }         
        order.push_back(key);
        hashMap[key] = {value, std::prev(order.end())};
        if (hashMap.size() > capacity) {
            hashMap.erase(order.front());
            order.pop_front();
        }
    }
};
