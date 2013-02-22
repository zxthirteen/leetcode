class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
