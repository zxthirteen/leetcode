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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
