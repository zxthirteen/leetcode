/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        if (s.empty()) return res;
        int start = 0, end = 0;
        res = 1;
        
        int *f = new int[256];
        memset(f, 0, 256*sizeof(int));
        f[s[0]] = 1;
        end = 1;
        while(end < s.size()) {
            if (f[s[end]] == 0) {
                f[s[end]] = 1;
            } else {
                while (s[start] != s[end]) {
                    f[s[start]]--;
                    start++;
                }
                start++;         
            }
            
            res = max(res, end-start+1);
            end++;
        }
        
        return res;
    }
};
