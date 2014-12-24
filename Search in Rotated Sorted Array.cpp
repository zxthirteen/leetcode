/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n-1;
        int m = 0;
        
        while (left <= right) {
            int m = (left + right)/2;
            if (A[m] == target) return m;
            
            if (A[left] < A[m]) {
                if (target > A[m] || target < A[left])
                    left = m + 1;
                else
                    right = m - 1;
            } else if (A[left] > A[m]) {
                if (target >= A[left] || target < A[m])
                    right = m - 1;
                else
                    left = m + 1;
            } else {
                // A[m] == A[left] means m == left && A[m] != target && left == right -1
                left = m + 1;
            }
        }
        
        return -1;
    }
};
