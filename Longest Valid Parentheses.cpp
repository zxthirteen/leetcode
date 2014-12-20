/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
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
