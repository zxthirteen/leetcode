class Solution {
public:
    vector<string> res;
    string oneres;
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
