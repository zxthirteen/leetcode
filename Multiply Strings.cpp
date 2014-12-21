/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int *x = new int[m+n];
        
        memset(x, 0, sizeof(int)*(m+n));
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                x[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        
        for (int i = m+n-1; i > 0; i--) {
            x[i-1] += x[i]/10;
            x[i] = x[i]%10;
        }
        
        int start = 0;
        while (x[start] == 0 && start < m+n-1) start++;
        
        string res(m+n-start, '0');
        for (int i = 0; i < m+n-start; i++) {
            res[i] = x[start+i] + '0';
        }
        
        return res;
    }
};
