/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
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
