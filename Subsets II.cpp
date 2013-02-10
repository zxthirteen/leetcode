class Solution {
public:
    vector<vector<int> > res;
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        sort(S.begin(), S.end());
        vector<int> r;
        dfs(S, 0, r);
        return res;
    }
    
    void dfs(vector<int> &s, int start, vector<int> r) {
        if (start == s.size()) {
            res.push_back(r);
            return;
        }
        
        int val = s[start];
        int end = start;
        
        while (end < s.size() && s[end] == val) end++;
        dfs(s, end, r);
        for (int i = start; i < end; i++) {
            r.push_back(val);
            dfs(s, end, r);
        }
    }
};
