class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> curr;
        vector<int> res;
        int diff {0};
                
        for (size_t i = 0; i < k; ++i) {
            curr.emplace_back(arr[i]);
            res.emplace_back(arr[i]);
            diff += abs(x - arr[i]);
        }

        int minDiff {diff};
        
        for (size_t i = k; i < arr.size(); ++i) {
            diff -= abs(x - curr.front());
            diff += abs(x - arr[i]);
            curr.pop_front();
            curr.emplace_back(arr[i]);
            if (diff < minDiff) {
                minDiff = diff;
                res.clear();
                for (size_t j = 0; j < curr.size(); j++) {
                    res.emplace_back(curr[j]);
                }
            }
        }

        return res;
    }
};