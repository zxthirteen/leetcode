class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
