/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int end = -1;
        int p = 0;
        
        for (; p < n; p++) {
            if (A[p] != elem) 
                A[++end] = A[p];
        }
        
        return end+1;
    }
};
