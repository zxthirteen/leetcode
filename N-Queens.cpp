class Solution {
vector<int> pos;
int m;
vector<vector<string> > res;
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pos = vector<int>(n, 0);
        res.clear();
        m = n;
        putq(0);
        
        return res;
    }
    
    void putq(int i) {
        if (i == m) {
            addres();
            return;
        }
        for (int j = 0; j < m; j++) {
            if (check(i, j)) {
                pos[i] = j;
                putq(i+1);
            }
        }
    }
    
    bool check(int i, int j) {
        for (int k = 0; k < i; k++) {
            if (pos[k] == j) return false;
        }
        
        int x = i, y = j;
        while (0 <= --x && 0 <= --y) {
            if (pos[x] == y) return false;
        }
        
        x = i;
        y = j;
        while (0 <= --x && ++y < m) {
            if (pos[x] == y) return false;
        }
        
        return true;
    }
    
    void addres() {
        vector<string> oneres(m, string(m, '.'));
        for (int i = 0; i < m; i++)
            oneres[i][pos[i]] = 'Q';
        res.push_back(oneres);
    }
};
