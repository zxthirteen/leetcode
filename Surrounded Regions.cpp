class Solution {
public:
    struct point {
        int x;
        int y;
        point(int xx, int yy): x(xx), y(yy) {}
    };
    
    vector<point> oneregion;
    int n;
    int m;
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') continue;
                if (!findregion(board, i, j))
                    unfilloneregion(board);
                oneregion.clear();
            }
        }
    }
    
    bool findregion(vector<vector<char>> &board, int x, int y) {
        queue<point> q;
        q.push(point(x, y));
        
        while (!q.empty()) {
            point p = q.front();
            q.pop();
            if (p.x == 0 || p.x == m-1) return false;
            if (p.y == 0 || p.y == n-1) return false;
            board[p.x][p.y] = 'X';
            oneregion.push_back(p);
            if (board[p.x-1][p.y] == 'O') q.push(point(p.x-1, p.y));
            if (board[p.x][p.y-1] == 'O') q.push(point(p.x, p.y-1));
            if (board[p.x+1][p.y] == 'O') q.push(point(p.x+1, p.y));
            if (board[p.x][p.y+1] == 'O') q.push(point(p.x, p.y+1));
        }
        
        return true;
    }
    
    void unfilloneregion(vector<vector<char>> &board) {
        for (int i = 0; i < oneregion.size(); i++) {
            board[oneregion[i].x][oneregion[i].y] = 'O';
        }
    }
};
