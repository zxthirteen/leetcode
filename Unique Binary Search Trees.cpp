class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return 1;
        int res = 0;
        for (int i = 0; i <= n-1; i++) {
            res += numTrees(i) * numTrees(n-1-i);
        }
        
        return res;
    }
};
