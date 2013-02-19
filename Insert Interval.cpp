/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), compInterval);
        
        if (newInterval.end < intervals[0].start) {
            intervals.insert(intervals.begin(), newInterval);
        } else if (newInterval.start > intervals[n-1].end){
            intervals.insert(intervals.end(), newInterval);
        } else {
            int startpos = 0, endpos = n-1;
            while (interval[startpos+1].start <= newInterval.end) startpos++;
            while (interval[endpos-1].end <= newInterval.start) endpos--;
            
            intervals[endpos].start = min(intarval[startpos].start, newInterval.start);
            intervals[endpos].end = max(intarval[endpos].end, newInterval.end);
            
            intervals.erase(intervals.begin() + startpos, intervals.begin() + endpos);
        }
        
        return intervals;
    }
    
    bool compInterval(Interval a, Interval b) {
        return a.start < b.start;
    }
};
