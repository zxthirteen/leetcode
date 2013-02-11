class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int res = 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> h(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            
            for (int j = 0; j < n; j++) {
                left[j] = j;
                
                while (left[j] -1 >= 0 && h[left[j] -1] >= h[j])
                    left[j] = left[left[j] -1];
            }
            
            for (int j = n-1; j >= 0; j--) {
                right[j] = j;
                
                while (right[j] +1 < n && h[right[j] +1] >= h[j])
                    right[j] = right[right[j] +1];
            }
            
            for (int j = 0; j < n; j++) {
                res = max(res, h[j] * (right[j] - left[j] +1));
            }
        }
        
        return res;
    }
};
