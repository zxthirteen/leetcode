/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6]
*/ 

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        find(candidates, 0, target, vector<int>());
        return res;
    }
    
    void find(vector<int> &candidates, int start, int target, vector<int> oneres) {
        if (target == 0) {
            res.push_back(oneres);
        } else if (start < candidates.size()) {
            // different from Combination Sum I:
            int newstart = start+1;
            // e.x. [12245]:
            // if we donot want the first 2, we ignore the second 2 neither.
            while (newstart < candidates.size() && candidates[newstart] == candidates[start])
                newstart++;
            find(candidates, newstart, target, oneres);
            
            if (target >= candidates[start]) {
                oneres.push_back(candidates[start]);
                find(candidates, start+1, target-candidates[start], oneres);
            }
        }
    }
};
