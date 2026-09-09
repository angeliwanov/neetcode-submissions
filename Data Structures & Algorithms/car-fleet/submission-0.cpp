class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> fleet;
        for (size_t i = 0; i < position.size(); ++i) {
            fleet.emplace_back(position[i], speed[i]);
        }
        std::sort(fleet.begin(), fleet.end());
        
        stack<pair<int,int>> stk;

        for (const auto& [p, s] : fleet) {               
            while (!stk.empty() && (double)(target - stk.top().first) / stk.top().second <= (double)(target - p) / s){
                stk.pop();
            } 
            stk.emplace(p,s);
        }

        return stk.size();
    }
};