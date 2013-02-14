class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        int m = word1.size(), n = word2.size();
        vector<vector<int> > res(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; i++) {
            res[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            res[0][j] = j;
        }
        
        int val;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                val = word1[i-1] == word2[j-1] ? res[i-1][j-1]:res[i-1][j-1]+1;
                val = min(val, res[i-1][j]+1);
                val = min(val, res[i][j-1]+1);
                res[i][j] = val;
            }
        }
        
        return res[m][n];
    }
};
