/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compInterval(Interval a, Interval b) {
    return a.start < b.start;
} 

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.empty()) return intervals;
        
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), compInterval);
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= res.back().end) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};
