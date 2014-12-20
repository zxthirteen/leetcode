/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int hlen = strlen(haystack);
        int nlen = strlen(needle);
        
        if (hlen < nlen) return -1;
        if (nlen == 0) return 0;
        
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
                if(i == nlen -1) return m;
                i++;
            } else {
                m = m + i - x[i];
                if (x[i] == -1) i = 0;  // x[0] is set -1
                else i = x[i];                
            }
        }
        
        return -1;
    }
};
