/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> res;
    string oneres;
    vector<string> generateParenthesis(int n) {
        res.clear();
        oneres = string(2*n, '(');
        
        dfs(n, 0, 0);
        
        return res;
    }
    
    void dfs(int n, int deep, int left) {
        if (left > n) return;

        if (deep == 2*n) {
            res.push_back(oneres);
            return;
        }
                
        if (2 * left == deep) {
            oneres[deep] = '(';
            dfs(n, deep+1, left+1);
        } else {
            oneres[deep] = '(';
            dfs(n, deep+1, left+1);
            oneres[deep] = ')';
            dfs(n, deep+1, left);
        }
    }
};
