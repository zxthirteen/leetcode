/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        find(candidates, 0, target, vector<int>());
        return res;
    }
    
    void find(vector<int> &candidates, int start, int target, vector<int> oneres) {
        if (target == 0) {
            res.push_back(oneres);
        } else if (start < candidates.size()) {
            find(candidates, start+1, target, oneres);
            for (int i = 1; i <= target/candidates[start]; i++) {
                oneres.push_back(candidates[start]);
                find(candidates, start+1, target-i*candidates[start], oneres);
            }
        }
    }
};
