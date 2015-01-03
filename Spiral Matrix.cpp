/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int n = matrix.size();
        vector<int> result;
        if (n == 0) return result;
        int startx = 0, starty = 0, endx = matrix.size()-1, endy = matrix[0].size()-1;
        
        while (endx >= startx && endy >= starty) {
            if (startx == endx) {
                for (int i = starty; i <= endy; i++) {
                    result.push_back(matrix[startx][i]);
                }
            } else if (starty == endy) {
                for (int i = startx; i <= endx; i++) {
                    result.push_back(matrix[i][starty]);
                }
            } else {
                for (int i = starty; i <= endy; i++) {
                    result.push_back(matrix[startx][i]);
                }
                for (int i = startx+1; i < endx; i++) {
                    result.push_back(matrix[i][endy]);
                }
                for (int i = endy; i >= starty; i--) {
                    result.push_back(matrix[endx][i]);
                }
                for (int i = endx-1; i > startx; i--) {
                    result.push_back(matrix[i][startx]);
                }
                
            }
            startx++;
            starty++;
            endx--;
            endy--;
        }
        
        return result;
    }
};