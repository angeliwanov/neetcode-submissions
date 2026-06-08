class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int subSum {0};
        int subArr = {0};
        
        size_t i {0};
        for (; i < k-1; ++i) {
            subSum += arr[i];
        }        

        for (; i < arr.size(); ++i) {
            subSum += arr[i];
            if (subSum / k >= threshold) {
                ++subArr;
            }
            subSum -= arr[i+1-k];
        }

        return subArr;
    }
};