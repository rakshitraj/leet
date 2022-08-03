#include <vector>

using namespace std;

class MyCalendar {
public:
    vector<pair<int,int>> calendar;

    MyCalendar() { }
    
    bool book(int start, int end) {
        if (!calendar.size()) return true;
        if (start > end) return false;

        for (auto el: calendar){
            if (max(el.first, start) < min(el.second, end)) return false;
        }
        calendar.push_back(std::make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */