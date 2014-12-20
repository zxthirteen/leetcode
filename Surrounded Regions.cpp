#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m;
    int n;
    void solve(vector<vector<char> > &board) {
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
    
    void fillopenregion(vector<vector<char> > &board, int x, int y) {
        if (board[x][y] != 'O') return;
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            board[p.first][p.second] = 'E';
            if (p.first > 0 && board[p.first-1][p.second] == 'O') q.push(make_pair(p.first-1, p.second));
            if (p.second> 0 && board[p.first][p.second-1] == 'O') q.push(make_pair(p.first, p.second-1));
            if (p.first < m-1 && board[p.first+1][p.second] == 'O') q.push(make_pair(p.first+1, p.second));
            if (p.second < n-1 && board[p.first][p.second+1] == 'O') q.push(make_pair(p.first, p.second+1));
        }
    }
};

int main() {
    return 0;
}
