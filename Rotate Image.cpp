/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n <= 1) return;
        
        for (int i = 0; i < n/2; i++) {
            for (int j = i; j < n-i-1; j++) {
                // i, j -> j, n-i-1 -> n-i-1, n-j-1 -> n-j-1, i
                int tmp = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = tmp;
            }           
        }
    }
};
