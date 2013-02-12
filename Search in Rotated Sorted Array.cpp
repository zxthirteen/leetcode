class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n-1;
        int m = 0;
        
        while (left <= right) {
            int m = (left + right)/2;
            if (A[m] == target) return m;
            
            if (A[left] < A[m]) {
                if (target > A[m] || target < A[left])
                    left = m + 1;
                else
                    right = m - 1;
            } else if (A[left] > A[m]) {
                if (target >= A[left] || target < A[m])
                    right = m - 1;
                else
                    left = m + 1;
            } else
                left = m + 1;
        }
        
        return -1;
    }
};
