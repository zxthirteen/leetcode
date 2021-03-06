/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        vector<vector<string>> r;
        
        for (int len = 1; len <= n; len++) {
            for (int start = 0; start <= n-len; start++) {
                if (len == 1) {
                    palin[start][start] = true;
                    continue;
                }
                int end = start + len - 1;
                if (s[start] == s[end]) {
                    if (start+1 == end) {
                        palin[start][end] = true;
                    } else {
                        palin[start][end] = palin[start+1][end-1];
                    }
                } else {
                    palin[start][end] = false;
                }
            }
        }
        
        vector<string> one;
        doPartition(s, 0, one, palin, r);
        return r;
    }
    
    void doPartition(string s, int start, vector<string> one, vector<vector<bool>>& palin, vector<vector<string>>& r) {
        int n = s.size();
        if (start == n) {
            r.push_back(one);
            return;
        }
        
        for (int end = start; end < n; end++) {
            if (palin[start][end]) {
                one.push_back(s.substr(start, end-start+1));
                doPartition(s, end+1, one, palin, r);
                one.pop_back();
            }
        }
    }
};