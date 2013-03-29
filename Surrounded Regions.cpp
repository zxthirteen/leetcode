class Solution {
public:
    struct point {
        int x;
        int y;
        point(int xx, int yy): x(xx), y(yy) {}
    };
    
    int n;
    int m;
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
    
    void fillopenregion(vector<vector<char>> &board, int x, int y) {
        if (board[x][y] != 'O') return;
        queue<point> q;
        q.push(point(x, y));
        
        while (!q.empty()) {
            point p = q.front();
            q.pop();
            
            board[p.x][p.y] = 'E';
            if (p.x > 0 && board[p.x-1][p.y] == 'O') q.push(point(p.x-1, p.y));
            if (p.y > 0 && board[p.x][p.y-1] == 'O') q.push(point(p.x, p.y-1));
            if (p.x < m-1 && board[p.x+1][p.y] == 'O') q.push(point(p.x+1, p.y));
            if (p.y < n-1 && board[p.x][p.y+1] == 'O') q.push(point(p.x, p.y+1));
        }
    }
};
