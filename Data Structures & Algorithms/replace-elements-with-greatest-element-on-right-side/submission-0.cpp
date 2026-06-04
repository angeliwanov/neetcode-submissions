class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxRight{-1};
        int tmp{};

        for (int i = arr.size() - 1; i >= 0; --i) {
            tmp = arr[i];
            arr[i] = maxRight;
            maxRight = max(maxRight, tmp);
        }

        return arr;       
    }
};