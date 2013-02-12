class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        
        int tail = 0;
        int p = 1;
        
        while (p < n) {
            if (A[p] != A[tail])
                A[++tail] = A[p];
            p++;
        }
        return tail+1;
    }
};
