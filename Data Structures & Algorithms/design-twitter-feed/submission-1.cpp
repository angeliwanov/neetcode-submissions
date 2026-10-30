class Twitter {
private:
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int timestamp {0};

public:
    Twitter() {            
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](pair<int,int> p1, pair<int,int> p2) {
            return p1.first > p2.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq;
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
            if (pq.size() > 10) {
                pq.pop();
            }            
        }
        for (auto followee : followers[userId]) {
            for (auto tweet : tweets[followee]) {
                pq.push(tweet);
                if (pq.size() > 10) {
                    pq.pop();
                }            
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return vector<int>(res.rbegin(), res.rend());
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followers[followerId].find(followeeId) != followers[followerId].end()) {
            followers[followerId].erase(followeeId);
        }
    }
};
