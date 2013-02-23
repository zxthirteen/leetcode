class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int end = -1;
        int p = 0;
        
        for (; p < n; p++) {
            if (A[p] != elem) 
                A[++end] = A[p];
        }
        
        return end+1;
    }
};
