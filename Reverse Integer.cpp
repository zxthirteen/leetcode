/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool posi = x >= 0;
        
        if (!posi) {
            if (x == INT_MIN) {
                return false;
            } else {
                x = -x;
            }
        }
        int count = 0;
        while (x) {
            if (count == 9 && (res > INT_MAX/10 || res == INT_MAX/10 && x/10 > INT_MAX%10)) {
                return 0;
            }
            res *= 10;
            res += x%10;
            x /= 10;
            count++;
        }
        
        return posi? res : -res;
    }
};
