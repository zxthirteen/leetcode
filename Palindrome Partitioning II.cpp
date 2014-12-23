class Solution {
public:
vector<vector<int> > mx;
    int minCut(string s) {
        int n = s.size();
        mx = vector<vector<int> >(n, vector<int>(n, -1));
        
        vector<int> res(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (isPalin(s, 0, i) == 1) {
                res[i] = 1;
                continue;
            }
            for (int start = 1; start <= i; start++) {
                if (isPalin(s, start, i) && res[start-1]+1 < res[i])
                    res[i] = res[start-1]+1;
            }
        }
        
        return res[n-1]-1;
    }
    
    bool isPalin(string &s, int i, int j) {
        if (mx[i][j] != -1) return mx[i][j];
        if (s[i] != s[j]) {
            mx[i][j] = 0;
            return mx[i][j];
        }
        
        if (i == j) {
            mx[i][j] = 1;
        } else if (i == j-1) {
            mx[i][j] = 1;
        } else {
            mx[i][j] = isPalin(s, i+1, j-1);
        }
        return mx[i][j];
    }
};