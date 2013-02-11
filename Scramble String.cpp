class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        
        bool ***res = new bool**[s1.size() + 1];
        
        for (int len = 1; len <= s1.size(); len++) {
            res[len] = new bool*[s1.size() - len +1];
            
            for (int p = 0; p <= s1.size() - len; p++) {
                res[len][p] = new bool[s2.size() - len +1];
                
                for (int q = 0; q <= s2.size() - len; q++) {
                    
                    res[len][p][q] = false;
                    if (string(s1, p, len) == string(s2, q, len)) {
                        res[len][p][q] = true;
                        continue;
                    }
                    
                    for (int i = 1; i < len; i++) {
                        if (res[i][p][q] && res[len-i][p+i][q+i] 
                        || res[i][p][q+len-i] && res[len-i][p+i][q]) {
                            res[len][p][q] = true;
                        }
                    }
                }
            }
        }
        
        return res[s1.size()][0][0];
    }
};
