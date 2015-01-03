/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<string> res;
        if (n == 0) return res;
        
        // DP
        vector<vector<bool> > match(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n-len; i++) {
                int j = i + len -1;
                string word = s.substr(i, len);
                if (dict.find(word) != dict.end()) {
                    match[i][j] = true;
                } else {
                    for (int k = i; k < j; k++) {
                        match[i][j] = match[i][k] && match[k+1][j];
                        if (match[i][j] == true) {
                            break;
                        }
                    }
                }
            }
        }
        if (!match[0][n-1]) {
            return res;
        }
        
        vector<string> one;
        dfs(s, dict, 0, one, res, match);
        return res;
    }
    
    void dfs(string s, unordered_set<string> &dict, int start, vector<string> &one, 
             vector<string> &res, vector<vector<bool> > &match) {
        int n = s.size();
        if (start == n) {
            stringstream ss;
            ss << one[0];
            for (int i = 1; i < one.size(); i++) {
                ss << ' ' << one[i];
            }
            res.push_back(ss.str());
        }
        for (int len = 1; len <= n - start; len++) {
            string word = s.substr(start, len);
            if (dict.find(word) != dict.end() && (start + len == n || match[start+len][n-1])) {
                one.push_back(word);
                dfs(s, dict, start + len, one, res, match);
                one.pop_back();
            }
        }
    }
};