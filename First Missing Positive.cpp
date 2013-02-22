class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0) return 1;
        
        for (int i = 0; i < n; i++) {
            if (A[i] <= 0 || A[i] > n) 
                A[i] = 0;
        }
        
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) continue;
            
            int t = abs(A[i]);
            if (A[t-1] > 0) {
                A[t-1] = -A[t-1];
            } else if(A[t-1] == 0) {
                A[t-1] = -abs(A[i]);
            }
        }
        
        int i;
        for (i = 0; i < n; i++) {
            if (A[i] >= 0) {
                break;
            }
        }
        return i+1;
    }
};
