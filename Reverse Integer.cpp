class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 0;
        
        while (x) {
            res *= 10;
            res += x%10;
            x /= 10;
        }
        
        return res;
    }
};
