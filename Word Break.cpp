/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        if (n == 0) return true;
        vector<bool> res(n, false);
        
        res[0] = find(dict.begin(), dict.end(), s.substr(0, 1)) != dict.end();
        for (int i = 1; i < n; i++) {
            for (int tail = i-1; tail >= -1; tail--) {
                string word = s.substr(tail +1, i - tail);
                if ((tail == -1 || res[tail]) && find(dict.begin(), dict.end(), word) != dict.end()) {
                    res[i] = true;
                    break;
                }
            }
        }
        return res.back();
    }
};