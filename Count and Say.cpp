/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        
        string s("1");
        for (int i = 1; i < n; i++) {
            s = nexts(s);
        }
        
        return s;
    }
    
    string nexts(string &s) {
        stringstream res;
        int num = 0;
        char c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                num++;
            } else {
                if (num > 0)
                    res << num << c;
                num = 1;
                c = s[i];
            }
        }
        res << num << c;
            
        return res.str();
    }
};
