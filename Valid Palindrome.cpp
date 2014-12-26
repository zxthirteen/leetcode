/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int p = 0, q = s.size()-1;
        
        while (p < q) {
            while (p < q && !isalnum(s[p])) p++;
            while (p < q && !isalnum(s[q])) q--;
            if (p >= q) break;
            if (s[p] == s[q] || isalpha(s[p]) && isalpha(s[q]) && 
                tolower(s[p]) == tolower(s[q])) {
                p++;
                q--;
            } else return false;
        }
        
        return true;
    }
};
