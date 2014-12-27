/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l = 0, u = num.size()-1;
        while (l <= u) {
            if (l == u) {
                return l;
            }
            if (l == u-1) {
                return num[l] > num[u] ? l : u;
            }
            int m = (l + u) /2;
            if (num[m] > num[m-1]) {
                if (num[m] > num[m+1]) {
                    return m;
                } else {
                    l = m + 1;
                }
            } else {
                u = m - 1;
            }
        }
        
        return l;
    }
};