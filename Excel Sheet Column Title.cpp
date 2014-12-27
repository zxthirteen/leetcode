/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

/*
非常tricky的一个问题！ base是26没有问题，但是在进位和确定每一位时都要用n-1而不是n
*/

class Solution {
public:
    string convertToTitle(int n) {
        vector<int> digits;
        int base = 26;
        while (n > 0) {
            // This is the trick part, should not be n%base
            digits.push_back((n-1)%base);
            n = (n-1)/base;
        }
        
        string res(digits.size(), 'A');
        for (int i = digits.size()-1; i >= 0; i--) {
            res[digits.size() - i -1] += digits[i];
        }
        return res;
    }
};