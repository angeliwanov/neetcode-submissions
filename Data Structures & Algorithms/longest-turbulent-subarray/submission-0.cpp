class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        size_t left{0};
        int maxLen{1};
        int compare {0};        
        
        for (size_t right = 1; right < arr.size(); ++right) {
            if (arr[right] - arr[right-1] == 0) {
                compare = 0;
                left = right;
            } else {
                if (arr[right] - arr[right-1] > 0) {
                    if (compare > 0) {
                        left = right - 1;
                    }
                    compare = 1;
                } else {
                    if (compare < 0) {
                        left = right -1;
                    }
                    compare = -1;
                }
            }
            maxLen = max(maxLen, static_cast<int>(right-left)+1);
        }

        return maxLen;
        
    }
};