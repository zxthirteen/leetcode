class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
