/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

/*
N多个问题：
1. 如果纯用减法，会超时；
2. 如果对dividend直接取整，INT_MIN将出错，解决办法是把所有数都变成负数来计算；
3. 换成负数计算后，1>>=1变成了-1>>=1不正常，因为-1左移还是-1，故-1的作为除数时必须单独考虑；
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        bool sign = (dividend ^ divisor) >> 31 == 0;
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
            res = dividend >= 0 ? dividend : -dividend;
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
        if (sign) {
            return res;
        } else {
            return 0 - res;
        }
    }
};
