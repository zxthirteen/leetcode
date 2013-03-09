class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        if (n == 0 || k == 0) return res;
        vector<int> sub;
        dfs(sub, n, 1, k);
        
        return res;
    }
    
    void dfs(vector<int> sub, int n, int start, int target) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        if (start == n+1) return;
        
        dfs(sub, n, start+1, target);
        sub.push_back(start);
        dfs(sub, n, start+1, target-1);
    }
};
