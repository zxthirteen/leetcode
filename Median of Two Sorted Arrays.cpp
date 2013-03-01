class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<m) return findMedian(A, B, 0, n-1, n, m);
        else return findMedian(B, A, 0, m-1, m, n);
    }
    
    double findMedian(int A[], int B[], int l, int r, int nA, int nB) {
        if (l>r) 
            return findMedian(B, A, max(0, (nA+nB)/2-nA), min(nB, (nA+nB)/2), nB, nA);
        
        // if nA+nB is even, try to find the right one in the two medians.
        // if nA+nB is even, try to find the only median.
        int i = (l+r)/2;
        int j = (nA+nB)/2 - i - 1;
        
        if (j>=0 && A[i] < B[j]) 
            return findMedian(A, B, i+1, r, nA, nB);
        else if (j<nB-1 && A[i] > B[j+1]) 
            return findMedian(A, B, l, i-1, nA, nB);
        else {
            if ( (nA+nB)%2 == 1 ) 
                return A[i];
            else if (i>0) 
                return (A[i]+max(B[j], A[i-1]))/2.0;
            else return (A[i]+B[j])/2.0;
        }
    }
};
