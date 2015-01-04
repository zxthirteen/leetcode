/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        if (n == 0) return res;
        int count = 1;
        for (int level = 0; level < (n+1)/2 ; level++) {
            int edge = n - 2 * level;
            if (edge == 1) {
                res[level][level] = count++;
            } else {
                for (int j = level; j < n - level-1; j++) {
                    res[level][j] = count++;
                }
                for (int i = level; i < n - level-1; i++) {
                    res[i][n - level -1] = count++;
                }
                for (int j = n - level -1; j > level; j--) {
                    res[n - level -1][j] = count++;
                }
                for (int i = n - level -1; i > level; i--) {
                    res[i][level] = count++;
                }
            }
        }
        return res;
    }
};