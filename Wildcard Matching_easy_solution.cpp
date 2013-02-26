class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!(s && p)) return false;
        if (*p == '\0') return *s == '\0';
        
        if (*s == *p || *p == '?' && *s != '\0') return isMatch(s+1, p+1);
        if (*p == '*') {
            // this make sure no "time limited exceeded"
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
