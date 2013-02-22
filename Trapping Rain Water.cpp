class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *h = new int[n];
        memset(h, 0, sizeof(int)*n);
        int sum = 0;
        
        // left side
        int maxh = A[0];
        for (int i = 1; i < n-1; i++) {
            h[i] = maxh;
            maxh = max(maxh, A[i]);
        }
        //  left side
        maxh = A[n-1];
        for (int i = n-2; i > 0; i--) {
            h[i] = min(h[i], maxh);
            maxh = max(maxh, A[i]); 
            if (h[i] > A[i]) sum += h[i]-A[i];
        }
        
        return sum;
    }
};
