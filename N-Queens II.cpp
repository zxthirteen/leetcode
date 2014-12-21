/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int totalNQueens(int n) {
        int r = 0;
        vector<int> s(n, -1);
        
        int i = 0;
        while (i >= 0) {
            if (i == n) {
                r++;
                i--;
            } else {
                do {s[i]++;} while (s[i] < n && !check(s, i));
                if (s[i] < n) {
                    i++;
                    continue;
                } else {
                    s[i] = -1;
                    i--;
                }
            }
        }
        return r;
    }
    
    bool check(vector<int> &s, int i) {
        int n = s.size();
        for (int row = 0; row < i; row++) {
            if (s[row] == s[i]) return false;
            if (s[i]-(i-row) >= 0 && s[row] == s[i]-(i-row)) return false;
            if (s[i]+(i-row) < n && s[row] == s[i]+(i-row)) return false;
        }
        return true;
    }
};
