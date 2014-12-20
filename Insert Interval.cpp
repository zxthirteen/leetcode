/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), compInterval);
        
        int n = intervals.size();
        if (newInterval.end < intervals[0].start) {
            intervals.insert(intervals.begin(), newInterval);
        } else if (newInterval.start > intervals[n-1].end){
            intervals.insert(intervals.end(), newInterval);
        } else {
            int startpos = 0, endpos = n-1;
            while (intervals[startpos].end < newInterval.start) 
                startpos++;
            while (intervals[endpos].start > newInterval.end) 
                endpos--;
            
            if (startpos <= endpos) {
                intervals[endpos].start = min(intervals[startpos].start, newInterval.start);
                intervals[endpos].end = max(intervals[endpos].end, newInterval.end);
                
                intervals.erase(intervals.begin() + startpos, intervals.begin() + endpos);
                // no change to the original intervals, just insert the new one
            } else {
                intervals.insert(intervals.begin() + startpos, newInterval);
            }
        
        }
        
        return intervals;
    }
};
