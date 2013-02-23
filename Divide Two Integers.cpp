/*
N多个问题：
1. 如果纯用减法，会超时；
2. 如果对dividend直接取整，INT_MIN将出错，解决办法是把所有数都变成负数来计算；
3. 换成负数计算后，1>>=1变成了-1>>=1不正常，因为-1左移还是-1，故-1的作为除数时必须单独考虑；
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool sign; 
        if (dividend >= 0 && divisor >= 0 || dividend < 0 && divisor < 0) sign = true;
        else sign = false;
        int res = 0;
        
        int times = -1;
        
        if (dividend > 0) dividend = 0 - dividend;
        if (divisor > 0) divisor = 0 - divisor;
    
        int old = divisor;
        while (dividend - divisor <= divisor) {
            divisor += divisor;
            times += times;
        }
        if (divisor == -1) 
            res = abs(dividend);
        else 
            while (1) {
                while (dividend > divisor && divisor <= old) {
                    divisor >>= 1;
                    times >>= 1;
                }
                if (divisor > old) break;
                dividend -= divisor;
                res += -times;
                if (dividend == 0) break;
            } 
        if (sign) return res;
        return 0 - res;
    }
};
