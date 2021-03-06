/*
Implement pow(x, n).
*/

class Solution {
public:
    double pow(double x, int n) {
        double res = 1;
        bool posi = n >= 0;
        
        n = abs(n);
        
        while (n > 0) {
            if (n % 2 == 1) {
                res *= x;
            }
            x *= x;
            n /= 2;
        }
        
        return posi? res: 1/res;
    }
};
