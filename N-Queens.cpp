/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

[pic]

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > r;
        vector<int> s(n, -1);
        
        int i = 0;
        while (i >= 0) {
            if (i == n) {
                addResult(r, s);
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
    
    void addResult(vector<vector<string> > &r, vector<int> &s) {
        vector<string> one(s.size(), string(s.size(), '.'));
        for (int i = 0; i < s.size(); i++) {
            one[i][s[i]] = 'Q';
        }
        r.push_back(one);
    }
};