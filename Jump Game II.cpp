class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return 0;
        
        int maxpos = 0;
        vector<int> jumps(n, 0);
        
        for (int i = 0; i <= maxpos; i++) {
            int pos = i+A[i];
            
            if (pos >= n-1) return jumps[i]+1;
            
            if (pos > maxpos) {
                for (int k = maxpos+1; k <= pos; k++) {
                    jumps[k] = jumps[i]+1;
                }
                maxpos = pos;
            }
        }
        
        return 0;
    }
};
