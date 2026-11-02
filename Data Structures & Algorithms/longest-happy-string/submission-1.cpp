class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        auto cmp = [](pair<int,char>& p1, pair<int,char>& p2) {return p1.first < p2.first;};
        priority_queue<pair<int,char>, vector<pair<int,char>>, decltype(cmp)> pq;
        if (a > 0) {
            pq.push({a,'a'});
        }
        if (b > 0) {
            pq.push({b,'b'});
        }
        if (c > 0) {
            pq.push({c,'c'});
        }
        string res;
        while (!pq.empty()) {
            auto p1 = pq.top();
            pq.pop();
            if (res.size() >= 2 && res.at(res.size()-1) == p1.second && res.at(res.size()-2) == p1.second) {
                if (pq.empty()) {
                    continue;
                }
                auto p2 = pq.top();
                pq.pop();
                res += p2.second;
                if (p2.first > 1) {
                    pq.push({p2.first-1, p2.second});
                }
            }
            res += p1.second;
            if (p1.first > 1) {
                pq.push({p1.first-1, p1.second});
            }
        }

        return res;
    }
};