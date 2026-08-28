class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void merge(vector<int>& arr, int l, int m, int r) {
        vector<int> left (arr.begin()+l, arr.begin()+m+1);
        vector<int> right (arr.begin()+m+1, arr.begin()+r+1);
        int i = l;
        int j = 0;
        int k = 0;

        while (j < left.size() and k < right.size()) {
            if (left[j] <= right[k]) {
                arr[i++] = left[j++];
            } else {
                arr[i++] = right[k++];
            }
        }

        while (j < left.size()) {
            arr[i++] = left[j++];
        }

        while (k < right.size()) {
            arr[i++] = right[k++];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }   

};