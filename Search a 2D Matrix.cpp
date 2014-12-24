/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int r = n*m-1;
        
        while (l <= r) {
            int mid = (l+r)/2;
            int i = mid/m;
            int j = mid%m;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target)
                r = mid-1;
            else 
                l = mid+1;
        }
        
        return false;
    }
};
