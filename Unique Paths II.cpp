class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
