/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> line = grid[0];
        for (int j = 1; j < n; j++) {
            line[j] += line[j-1];
        }
        
        for (int i = 1; i < m; i++) {
            line[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                line[j] = min(line[j-1], line[j]) + grid[i][j];
            }
        }
        
        return line.back();
    }
};
