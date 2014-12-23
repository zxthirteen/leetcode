/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        
        int tail = 0, p = 1;
        bool dup = false;
        
        while (p < n) {
            if (A[p] != A[tail]) {
                dup = false;
                A[++tail] = A[p];
            } else {
                if (!dup) {
                    A[++tail] = A[p];
                    dup = true;
                }
            }
            p++;
        }
        
        return tail+1;
    }
};
