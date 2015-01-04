/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

/*
O(logn), 但是最差情况是O(n)
与I题唯一的不同是最后相等的情况里，把left到mid全部遍历一下，然后left = m+1
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n-1;
        int m = 0;
        
        //4 5 6 7 0 1 2
        while (left <= right) {
            int m = (left + right)/2;
            if (A[m] == target) return true;
            
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
                for (int i = left; i < m; i++) {
                    if (A[i] == target) {
                        return true;
                    }
                }
                left = m + 1;
            }
        }
        
        return false;
    }
};