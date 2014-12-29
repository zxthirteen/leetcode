/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

/*
有一个test case不能过：
Input:	-1, -2147483648
Output:	"0.0000000000000000000000000000001"
Expected:	"0.0000000004656612873077392578125"
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream res;
        string resultstring;
        if (numerator == INT_MIN) {
            if (denominator == 1) {
                res << numerator;
                return res.str();
            } else if (denominator == -1) {
                res << numerator;
                resultstring = res.str();
                resultstring.erase(0, 1);
                return resultstring;
            }
        }
        
        bool posi = (numerator ^ denominator) >> 31 == 0;
        if (!posi && numerator != 0) {
            res << '-';
        }
        if (numerator < 0) {
            numerator = -numerator;
        } 
        if (denominator < 0) {
            denominator = -denominator;
        }
        res << numerator/denominator;
        if (numerator % denominator == 0) {
            return res.str();
        }
        
        res << '.';
        int dot = res.str().size();
        vector<int> midnum;
        int p = numerator % denominator;
        
        vector<int>::iterator pos;
        while (true) {
            if (p == 0) {
                break;
            }
            p *= 10;
            pos = find(midnum.begin(), midnum.end(), p);
            if (pos != midnum.end()) {
                break;
            }
            midnum.push_back(p);
            res << p / denominator;
            p = p % denominator;
        }
        
        if (p == 0) {
            return res.str();
        }
        res << ')';
        
        resultstring = res.str();
        resultstring.insert(pos - midnum.begin() + dot, 1, '(');
        return resultstring;
    }
};