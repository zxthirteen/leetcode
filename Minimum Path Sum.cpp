class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
