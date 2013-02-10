class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p = m -1;
        int q = n -1;
        
        for (int i = m + n -1; i >= 0; i--) {
            if (p == 0) {
                A[i] = B[q];
                q--;
                continue;
            }
            if (q == 0) {
                A[i] = A[p];
                p--;
                continue;
            }
            
            if (A[p] >= B[q]) {
                A[i] = A[p];
                p--;
            } else {
                A[i] = B[q];
                q--;
            }
        }
    }
};
