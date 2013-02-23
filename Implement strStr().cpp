class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hlen = strlen(haystack);
        int nlen = strlen(needle);
        
        if (hlen < nlen) return NULL;
        if (*needle == NULL) return haystack;
        
        int x[nlen];
        
        x[0] = -1;
        x[1] = 0;
        int pos = 2;
        int subend = 0;
        while (pos < nlen) {
            if (needle[pos-1] == needle[subend]) {
                x[pos++] = ++subend;
            } else if (subend > 0){
                subend = x[subend];
            } else {    // subend == 0
                x[pos++] = 0;
            }
         }
        
        int i = 0;
        for (int m = 0; m <= hlen-nlen;) {
            if (haystack[m+i] == needle[i]) {
                if(i == nlen -1) return &haystack[m];
                i++;
            } else {
                m = m + i - x[i];
                if (x[i] == -i-1) i = 0;  // x[0] is set -1
                if (i != 0) i = x[i];                
            }
            
         }
        
        return NULL;
    }
};
