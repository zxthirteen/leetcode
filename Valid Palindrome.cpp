class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
