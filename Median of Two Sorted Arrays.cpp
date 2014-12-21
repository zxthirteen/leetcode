/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m+n)%2 == 0) 
            return (find(A, m, B, n, (m+n)/2) + find(A, m, B, n, (m+n)/2+1)+0.0)/2;
        else 
            return find(A, m, B, n, (m+n)/2+1);
    }
    
    int find(int A[], int nA, int B[], int nB, int k) {
        if(nA == 0) return B[k-1];
        if(nB == 0) return A[k-1];
        if(k == 1) return min(A[0], B[0]);

        int ax = nA/2;
        int bx = nB/2;
            
        if (A[ax] > B[bx]) {
            if (ax + bx + 1 >= k) {
                find(A, ax, B, nB, k);
            } else {
                find(A, nA, B + bx + 1, nB - bx - 1, k - bx - 1);
            }
        } else {
            if (ax + bx + 1 >= k) {
                find(A, nA, B, bx, k);
            } else {
                find(A + ax + 1, nA - ax - 1, B, nB, k - ax - 1);
            }
        }
    }
};
