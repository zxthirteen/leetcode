/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int digits = 0;
        int base = 1;
        while (x >= base) {
            digits++;
            if (base > INT_MAX/10) break;
            base *= 10;
        }
        
        int base1 = digits-1;
        int base2 = 0;
        while (base1 > base2) {
            int a = x % (int)pow(10, base1+1);
            a = a/(int)pow(10, base1);
            int b = x % (int)pow(10, base2+1);
            b = b/(int)pow(10, base2);
            if (a != b) return false;
            base1--;
            base2++;
        }
        return true;
    }
};
