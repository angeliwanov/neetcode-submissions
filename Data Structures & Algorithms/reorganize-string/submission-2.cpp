class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> chars;
        for (char ch: s) {
            chars[ch] += 1;
        }
        auto cmp = [](pair<char,int>& p1, pair<char,int>& p2) {return p1.second < p2.second;};
        priority_queue<pair<char, int>, vector<pair<char,int>>, decltype(cmp)> pq;
        for (auto& item: chars) {            
            pq.push({item.first, item.second});
        }

        string res;
        while (pq.size() > 1) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();          
            res += p1.first;
            res += p2.first;            
            if (p1.second > 1) {
                pq.push({p1.first, p1.second-1});
            }
            if (p2.second > 1) {
                pq.push({p2.first, p2.second-1});
            }
        }

        if (pq.empty()) {
            return res;
        }
        if (pq.top().second > 1) {
            return "";
        }       
        return res + pq.top().first;        
    }
};