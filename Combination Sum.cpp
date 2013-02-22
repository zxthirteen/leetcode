class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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
            find(candidates, start+1, target, oneres);
            for (int i = 1; i <= target/candidates[start]; i++) {
                oneres.push_back(candidates[start]);
                find(candidates, start+1, target-i*candidates[start], oneres);
            }
        }
    }
};
