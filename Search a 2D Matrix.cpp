class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        
        int x = m -1, y = 0;
        while (true) {
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] > target) {
                if (x == 0) return false;
                else x = x -1;
            } else {
                if (y == n -1) return false;
                else y = y +1;
            }
        }
        
        return false;
    }
};
