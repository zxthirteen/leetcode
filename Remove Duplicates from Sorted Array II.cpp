class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
