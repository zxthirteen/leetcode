/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n;) {
            // If swap A[i] with some val else, need check A[i] again.
            // To avoid infinite loop, will check if equal before check.
            if (A[i] > 0 && A[i] <= n && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
            } else {
                i++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (A[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};
