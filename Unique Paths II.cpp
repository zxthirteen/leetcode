/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> line = obstacleGrid[0];
        line[0] = obstacleGrid[0][0] ? 0:1;
        for (int j = 1; j < n; j++) {
            line[j] = obstacleGrid[0][j] ? 0:line[j-1];
        }
        
        for (int i = 1; i < m; i++) {
            line[0] = obstacleGrid[i][0] ? 0:line[0];
            for (int j = 1; j < n; j++) {
                line[j] = obstacleGrid[i][j] ? 0:line[j-1] + line[j];
            }
        }
        
        return line.back();
    }
};
