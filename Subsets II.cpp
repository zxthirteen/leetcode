/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > res;
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
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
