class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;

        for (auto asteroid: asteroids) {
            if (asteroid > 0) {
                stk.push_back(asteroid);
            } else {
                while (!stk.empty() && stk.back() > 0) {
                    if (stk.back() < abs(asteroid)) {
                        stk.pop_back();
                    } else if (stk.back() == abs(asteroid)) {
                        stk.pop_back();
                        asteroid = 0;
                        break;
                    } else {
                        asteroid = 0;
                        break;
                    }
                }

                if (asteroid != 0) {
                    stk.push_back(asteroid);
                }                       
            }
        }

        return stk;
    }
};