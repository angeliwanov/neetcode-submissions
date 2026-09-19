class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!store.contains(key)) {
            return "";
        }
        string res = "";
        int left {0};
        int right {static_cast<int>(store[key].size()) - 1};   

        while (left <= right) {
            int mid {left + (right-left) / 2};
            if (store[key][mid].first == timestamp) {
                return store[key][mid].second;
            } else if  (store[key][mid].first < timestamp) {
                res = store[key][mid].second;
                left = mid + 1;            
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};
