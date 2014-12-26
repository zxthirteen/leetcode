/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    int m, n;
    bool exist(vector<vector<char> > &board, string word) {
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
