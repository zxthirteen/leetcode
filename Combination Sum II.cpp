class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
