class Solution {
public:
    int m, n;
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.empty()) return false;
        m = board.size();
        n = board[0].size();
        
        vector<vector<bool> > f(m, vector<bool>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, board, word, f)) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(int x, int y, int k, vector<vector<char> > &board, string &word, vector<vector<bool> > &f) {
        if (k == word.size()) return true;
        if (word[k] != board[x][y]) return false;
        if (k == word.size() -1) return true;
        
        f[x][y] = true;
        if (x-1 >= 0 && !f[x-1][y] && dfs(x-1, y, k+1, board, word, f)) return true;
        if (x+1 < m && !f[x+1][y] && dfs(x+1, y, k+1, board, word, f)) return true;
        if (y-1 >= 0 && !f[x][y-1] && dfs(x, y-1, k+1, board, word, f)) return true;
        if (y+1 < n && !f[x][y+1] && dfs(x, y+1, k+1, board, word, f)) return true;
        f[x][y] = false;
        
        return false;
    }
};
