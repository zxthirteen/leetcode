class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        int word = 0;
        
        while (*s) {
            if (*s == ' ') {
                if (*(s-1) != ' ') {
                    word = len;
                    len = 0;
                }
            } else {
                len++;
            }
            s++;
        }
        
        return len ? len:word;
    }
};
