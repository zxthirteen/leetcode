/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        vector<int> x(3, 0);
        int n = s.size();
        if (n%2) return false;
        stack<char> pare;
        
        for (int p = 0; p < n; p++) {
            switch(s[p]) {
                case '(': 
                    pare.push(s[p]);
                    break;
                case ')':
                    if (pare.empty() || pare.top() != '(') return false;
                    pare.pop();
                    break;
                    
                case '[':
                    pare.push(s[p]);
                    break;
                case ']':
                    if (pare.empty() || pare.top() != '[') return false;
                    pare.pop();
                    break;
                    
                case '{':
                    pare.push(s[p]);
                    break;
                case '}':
                    if (pare.empty() || pare.top() != '{') return false;
                    pare.pop();
                    break;
            }
        }
        
        return pare.empty();
    }
};
