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
        string c;
        if (a.size() < b.size()) {
            c = b;
            b = a;
            a = c;
        }
        int p = a.size(), q = b.size();
        int carry = 0;
        int val = 0;
        c = a;
        while (--q, --p >= 0) {
            val = carry + (a[p] - '0');
            if (q >= 0)
                val += b[q] - '0';
            c[p] = val%2 + '0';
            carry = val/2;
        }
        
        if (carry) c.insert(c.begin(), '1');
        return c;
    }
};
