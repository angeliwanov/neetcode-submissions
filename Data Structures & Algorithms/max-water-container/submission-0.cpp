class Solution {
public:
    int maxArea(vector<int>& heights) {
        size_t left{0};
        size_t right{heights.size()-1};
        int maxWater{0};

        while (left < right) {
            maxWater = max(maxWater, min(heights[left], heights[right]) * static_cast<int>(right - left));
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
