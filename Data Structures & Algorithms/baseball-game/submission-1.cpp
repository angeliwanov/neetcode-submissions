class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> stk;
        
        for (const std::string& op: operations) {
            if (op == "+") {
                stk.push_back(stk.back() + stk.end()[-2]);
            } else if (op == "D") {        
                stk.push_back(stk.back() * 2);
            } else if (op == "C") {
                stk.pop_back();
            } else {
                stk.push_back(std::stoi(op));
            }
        }

        return std::accumulate(stk.begin(), stk.end(), 0);
    }
};