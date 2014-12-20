/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combine(int n, int k) {
        res.clear();
        if (n == 0 || k == 0) return res;
        vector<int> oneres;
        dfs(n, k, 0, oneres);
        return res;
    }
    
    void dfs(int n, int target, int start, vector<int> oneres) {
        if (target == 0) {
            res.push_back(oneres);
            return;
        }
        if (start == n) return;
        
        dfs(n, target, start+1, oneres);
        oneres.push_back(start+1);
        dfs(n, target-1, start+1, oneres);
    }
};