class Solution {
public:
    int getTime(vector<int>& piles, int speed) {
        int time = 0;

        for (const auto& pile: piles) {            
            time += (pile + speed - 1) / speed;
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {        
        int low = 1;
        int high = std::ranges::max(piles);
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (getTime(piles, mid) <= h) {
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
