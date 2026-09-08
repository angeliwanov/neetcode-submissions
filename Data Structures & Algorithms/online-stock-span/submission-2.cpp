class StockSpanner {
private:
    int day {0};
    vector<pair<int,int>> prices;
    
public:
    StockSpanner() {
       prices.emplace_back(day, INT_MAX);    
    }
    
    int next(int price) {
        ++day;
        while (prices.back().second <= price) {
            prices.pop_back();
        }
        prices.emplace_back(day, price);
        return day - prices[prices.size()-2].first;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */