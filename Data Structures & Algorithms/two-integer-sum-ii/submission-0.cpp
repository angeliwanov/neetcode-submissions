class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        size_t left{0};
        size_t right{numbers.size()-1};

        while (left < right) {
            int currSum = numbers[left] + numbers[right];
            if (currSum > target) {
                right--;
            } else if (currSum < target) {
                left++;
            } else {
                return {static_cast<int>(left)+1, static_cast<int>(right)+1};
            }
        }

        return {-1,-1};
    }
};
