/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int res = 0;
        set<int> all;
        for (int i = 0; i < num.size(); i++) {
            all.insert(num[i]);
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (all.find(num[i]) != all.end()) {
                res = max(res, getcount(all, num[i]-1, false) + getcount(all, num[i], true));
            }
        }
        
        return res;
    }
    
    int getcount(set<int> &all, int t, bool up) {
        int total = 0;
        while (all.find(t) != all.end()) {
            total++;
            all.erase(t);
            t += up? 1: -1;
        }
        return total;
    }
};
