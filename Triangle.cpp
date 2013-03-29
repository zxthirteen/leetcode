class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        if (n == 0) return 0;
        if (n == 1) return triangle[0][0];
        
        vector<int> sum(triangle.back());
        
        // DP
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                sum[j] = triangle[i][j] + min(sum[j], sum[j+1]);
            }
        }
        
        return sum[0];
    }
};
