class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        if (S.empty()) return res;
        sort(S.begin(), S.end());
        
        vector<int> sub;
        dfs(S, 0, sub);
        
        return res;
    }
    
    void dfs(vector<int> &s, int k, vector<int> sub) {
        if (k == s.size()) {
            res.push_back(sub);
            return;
        } else {
            dfs(s, k+1, sub);
            sub.push_back(s[k]);
            dfs(s, k+1, sub);
        }
    }
};
