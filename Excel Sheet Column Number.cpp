/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        const int base = 26;
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res *= base;
            int val = s[i] - 'A' + 1;
            res += val;
        }
        return res;
    }
};