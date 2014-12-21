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

/*
This is using DP and more efficient but runtime error with input:
eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj
but local all correct.
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> palin;
        vector<vector<string>> r;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vector<bool> line(n, false);
            palin.push_back(line);
        }
        
        for (int len = 1; len <= n; len++) {
            for (int start = 0; start < n; start++) {
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

/*
This soluntion is force search be Accepted.
*/

class Solution {
public:
vector<vector<string> > res;
    vector<vector<string>> partition(string s) {
        res.clear();
        
        dfs(0, s, vector<string>());
        return res;
    }
    
    void dfs(int start, string s, vector<string> v) {
        if (start == s.size()) {
            res.push_back(v);
            return;
        }
        
        for (int end = start; end < s.size(); end++) {
            string ss = s.substr(start, end-start+1);
            if (isplin(ss)) {
                v.push_back(ss);
                dfs(end+1, s, v);
                v.pop_back();
            }
        }
    }
    
    bool isplin(string s) {
        int p = 0, q = s.size()-1;
        while (p < q) {
            if (s[p] != s[q]) return false;
            p++;
            q--;
        }
        return true;
    }
};
