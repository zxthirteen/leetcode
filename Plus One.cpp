/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res(digits);

        res.back()++;
        int carry = res.back()/10;
        res.back() = res.back()%10;
        
        for (int i = res.size()-2; i >= 0; i--) {
            if (carry == 0) break;
            res[i] = res[i] + carry;
            carry = res[i]/10;
            res[i] = res[i]%10;
        }
        
        if (carry) res.insert(res.begin(), 1);
        return res;
    }
};
