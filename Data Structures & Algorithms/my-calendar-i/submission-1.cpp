class MyCalendar {
   private:
    std::vector<std::pair<int, int>> events;

   public:
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        for (auto& [start, end] : events) {
            if (startTime < end && endTime > start) {
                return false;
            }
        }
        events.emplace_back(startTime, endTime);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */