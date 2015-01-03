/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
*/

class Solution {
public:
    const int block = 3;
    const int n = 9;
    void solveSudoku(vector<vector<char> > &board) {
        dfs (board, 0);
    }
    
    bool dfs(vector<vector<char> > &board, int pos) {
        if (pos == n * n) {
            return true;
        }
        int row = pos / n;
        int col = pos % n;
        if (board[row][col] == '.') {
            for (int i = 0; i < n; i++) {
                char c = '1' + i;
                board[row][col] = c;
                if (check(board, pos, c) && dfs(board, pos+1)) {
                    // The question says only one solution
                    return true;
                }
            }
            board[row][col] = '.';
            return false;
        } else {
            return dfs(board, pos +1);
        }
    }
    
    bool check(vector<vector<char> > &board, int pos, char c) {
        int row = pos / n;
        int col = pos % n;
        for (int i = 0; i < n; i++) {
            if (i != col && board[row][i] == c) {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != row && board[i][col] == c) {
                return false;
            }
        }
        
        int startrow = row - row % block;
        int startcol = col - col % block;
        for (int i = 0; i < block; i++) {
            for (int j = 0; j < block; j++) {
                if (startrow + i != row && startcol + j != col &&
                    board[startrow + i][startcol + j] == board[row][col]) {
                        return false;
                }
            }
        }
        
        return true;
    }
};