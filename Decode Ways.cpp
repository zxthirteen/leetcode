/*
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int* ways = new int[s.size()];
        ways[0] = s[0] >= '1' && s[0] <= '9' ? 1: 0;

        for (int i = 1; i < s.size(); i++) {
            ways[i] = 0;
            string sub = string(s, i, 1);
            if ("1" <= sub && sub <= "9") {
                ways[i] += ways[i-1];
            }
            sub = string(s, i-1, 2);
            if ("10" <= sub && sub <= "26") {
                if (i -2 >= 0) {
                    ways[i] += ways[i-2];
                } else {
                    ways[i] += 1;
                }
            }
        }
        
        return ways[s.size() -1];
    }
};