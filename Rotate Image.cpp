class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
