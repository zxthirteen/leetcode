/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
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
