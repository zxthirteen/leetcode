class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size() == 0) return 0;

        int max = 0;
        int len = 0;
        int count = 0;
        int pos = 0;
        
        // from left to right
        for (pos = 0; pos < s.size(); pos++) {
            if (s[pos] == '(') count++;
            else count--;
            len++;
            if (count == 0) {
                max = len>max ? len: max;
            } else if (count < 0) {
                len = 0;
                count = 0;
            }
        }
        
        // from right to left
        // for the case "(()"
        count = 0;
        len = 0;
        for (pos = s.size() -1; pos >= 0; pos--) {
            if (s[pos] == '(') count++;
            else count--;
            len++;
            if (count == 0) {
                max = len>max ? len: max;
            } else if (count > 0) {
                len = 0;
                count = 0;
            }
        }
        
        return max;
    }
};
