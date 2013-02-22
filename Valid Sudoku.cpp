class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<char> num;
        const int n = 9;
        // lines:
        for (int i = 0; i < n; i++) {
            num.clear();
            for (int j = 0; j < n; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    if (num.count(board[i][j]) > 0) return false;
                    else num.insert(board[i][j]);
                }
            }
        }
        // columns:
        for (int j = 0; j < n; j++) {
            num.clear();
            for (int i = 0; i < n; i++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    if (num.count(board[i][j]) > 0) return false;
                    else num.insert(board[i][j]);
                }
            }
        }
        
        for (int x = 0; x < n; x+=3) {
            for (int y = 0; y < n; y+=3) {
                num.clear();
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[x+i][y+j] >= '1' && board[x+i][y+j] <= '9') {
                            if (num.count(board[x+i][y+j]) > 0) return false;
                            else num.insert(board[x+i][y+j]);
                        }
                    }
                }
            } 
        }
        
        return true;
    }
};
