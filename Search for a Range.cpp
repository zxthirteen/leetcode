/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

/*
很重要，寻找第一匹配和最后匹配，编程珠玑的P93有第一匹配的例子，我仿照写出了最后匹配
如果只是找任意匹配就比较简单：
l = 0; u = n - 1;
loop 
    // invaiant: A[l] <= target <= A[u]
    if l > u
        p = -1; break
    m = (l + u) /2
    case A[m] == t : return m;
    case A[m] < t  : l = m+1;
    case A[m] > t  : u = m-1;
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        
        int l = -1, u = n;
        // find first match
        // invariant: A[l] < target <= A[u]
        while (l < u-1) {
            int m = (l + u)/2;
            if (target > A[m]) {
                l = m;   
            } else {
                u = m;
            }
        }
        if (u >= n || A[u] != target) {
            return res;
        } else {
            res[0] = u;
        }
        
        // find last match
        // invariant: A[l] <= target < A[u]
        l = -1;
        u = n;
        while (l < u-1) {
            int m = (l + u)/2;
            if (target >= A[m]) {
                l = m;
            } else {
                u = m;
            }
        }
        // because we have find the first match, so there must be a match here
        // otherwise, we will need to check (l <= 0 || A[l] == target)
        res[1] = l;
        
        return res;
    }
};