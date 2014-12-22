/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

/*
This is dfs solution, actually the iterative solution in question Permutation can also resolve this problem.
*/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // DFS
        sort(num.begin(), num.end());
        int n = num.size();
        vector<vector<int> > result;
        if (n == 0) return result;
        vector<bool> visited(n, false);
        
        vector<int> one;
        dfs(visited, 0, num, one, result);
        return result;
    }
    
    void dfs(vector<bool> &visited, int k, vector<int> &num, vector<int> &one, vector<vector<int> > &result) {
        int n = visited.size();
        if (k == n) {
            result.push_back(one); 
            return;
        }
        int last = -1;
        for(int i = 0; i < n; i++) {
            if (visited[i] == false && (last == -1 || num[i] != num[last])) {
                visited[i] = true;
                one.push_back(num[i]);
                last = i;
                dfs(visited, k+1, num, one, result);
                one.pop_back();
                visited[i] = false;
            }
        }
    }
};