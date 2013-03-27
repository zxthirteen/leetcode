class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
