class Solution {
public:
vector<vector<string> > res;
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
