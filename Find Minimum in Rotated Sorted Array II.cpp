/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

/* 如果有重复元素，二分法不起作用，有一种情况是没法判断在左还是在右，这题在coding interview的书里也有 */

class Solution {
public:
    int findMin(vector<int> &num) {
        int res = num[0];
        for (int i = 1; i < num.size(); i++) {
            res = min(res, num[i]);
        }
        return res;
    }
};