/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > subsets(vector<int> &S) {
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
