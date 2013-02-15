class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = 1, b = 2;
        int tmp = 0;
        for (int i = 1; i < n; i++) {
            tmp = a + b;
            a = b;
            b = tmp;
        }
        
        return a;
        
    }
};
