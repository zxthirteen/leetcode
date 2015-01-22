/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int t = max(m, n);
        string c(t+1, '0');
        int carry = 0;
        for (int i = t; i >= 0; i--) {
            m--;
            n--;
            int sum = carry;
            if (m >= 0) {
                sum += a[m] - '0';
            }
            if (n >= 0) {
                sum += b[n] - '0';
            }
            c[i] = sum%2 + '0';
            carry = sum/2;
        }
        return c[0] == '1' ? c : c.substr(1, c.size()-1);
    }
};