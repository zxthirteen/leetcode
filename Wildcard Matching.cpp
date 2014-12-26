/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

/*
This simple solution will Time Limit Exceeded
https://oj.leetcode.com/discuss/10133/linear-runtime-and-constant-space-solution
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!(s && p)) return false;
        if (*p == '\0') return *s == '\0';
    
        if (*s == *p || *p == '?' && *s != '\0') return isMatch(s+1, p+1);
        if (*p == '*') {
            if (*(p-1) == '*') return isMatch(s, p+1);

            while (*s != '\0') {
                if (isMatch(s, p+1)) return true;
                s++;
            }   
            if (isMatch(s,p+1)) return true;
        }   
        return false;
    }
};

/*
Accepted code
做法：先根据*号把patern分段，然后找每段在s中的位置，如果有一个找不到，就是false
如果有多个匹配其实无所谓，只要找到第一个就可以，因为*可以处理后面的任意字符
*/

class Solution {
public:
    // split the pattern by '*'
    void extractSubPatterns(const char *p, vector<string> &subpatterns) {
        string subpattern;
        while (1) {
            if (*p == '\0') {
              if (!subpattern.empty())
					subpatterns.push_back(subpattern);
                break;
            } else if (*p == '*') {
                if (!subpattern.empty())
					subpatterns.push_back(subpattern);
                subpattern.clear();
            } else {
                subpattern.push_back(*p);
            }
            p++;
        }
    }

    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return (*s == '\0');
        bool starbegin = false, starend = false;
        if (*p == '*')
            starbegin = true;
        if (*(p+strlen(p)-1) == '*')
            starend = true;
            
        vector<string> subpatterns;
        extractSubPatterns(p, subpatterns);
        const char *pos = s;
        
        int i = 0;
        for (i = 0; i < subpatterns.size(); i++) {
            // find the ith sub pattern
            bool got = false;
            for (const char *posbegin = pos; posbegin != '\0'; posbegin++) {
                int k;
                for (k = 0; k < subpatterns[i].size(); k++) {
                    if (*(posbegin+k) == '\0') return false;
					if (subpatterns[i][k] != '?' && *(posbegin+k) != subpatterns[i][k]) break;
                }
                if (k == subpatterns[i].size()) {
                    pos = posbegin + k;
                    got = true;
                    if (i == 0 && !starbegin && posbegin != s)
                        got = false;
                    if (i+1 == subpatterns.size() && !starend && *pos != '\0')
                        got = false;
                    else 
                        break;
                }
            }
            if (got == false) break;
        }
        
        return (i == subpatterns.size());
    }
};
