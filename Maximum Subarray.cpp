class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        
        int res = INT_MIN;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += A[i];
            res = max(res, sum);
            if (sum <= 0) {
                sum = 0;
            }
        }
        
        return res;
    }
};
