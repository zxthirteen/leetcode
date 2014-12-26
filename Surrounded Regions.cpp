/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
    int m;
    int n;
    void solve(vector<vector<char> > &board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
            
        for (int i = 0; i < m; i++) {
            fillopenregion(board, i, 0); 
            fillopenregion(board, i, n-1);
        }   
        for (int j = 0; j < n; j++) {
            fillopenregion(board, 0, j); 
            fillopenregion(board, m-1, j); 
        }   
            
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'E')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }   
        }   
    }   
    
    void fillopenregion(vector<vector<char> > &board, int x, int y) {
        if (board[x][y] != 'O') return;
        stack<pair<int, int> > s;
        // I tried use queue, but lead to time limit, using stack will resovle.
        s.push(make_pair(x, y));
            
        while (!s.empty()) {
            pair<int, int> p = s.top();
            s.pop();

            board[p.first][p.second] = 'E';
            if (p.first > 0 && board[p.first-1][p.second] == 'O') s.push(make_pair(p.first-1, p.second));
            if (p.second> 0 && board[p.first][p.second-1] == 'O') s.push(make_pair(p.first, p.second-1));
            if (p.first < m-1 && board[p.first+1][p.second] == 'O') s.push(make_pair(p.first+1, p.second));
            if (p.second < n-1 && board[p.first][p.second+1] == 'O') s.push(make_pair(p.first, p.second+1));
        }
    }
};