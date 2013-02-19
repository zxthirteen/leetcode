class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return true;
        
        for (int i = n-1; i >= 0; i--) {
            int base = A[i];
            for (int k = 1; k <= base && i+k < n; k++) {
                A[i] = max(A[i], k + A[i+k]); 
            }
        }
        
        return A[0] >= n-1;
    }
};
