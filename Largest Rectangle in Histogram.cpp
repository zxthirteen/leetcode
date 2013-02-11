class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.empty()) return 0;
        
        int res = 0;
        int n = height.size();
        
        vector<int> left(n, 0), right(n, 0);
        
        for (int i = 0; i < n; i++) {
            left[i] = i;
            while (left[i] -1 >= 0 && height[left[i] -1] >= height[i])
                left[i] = left[left[i] -1];
        }
        
        for (int i = n-1; i >= 0; i--) {
            right[i] = i;
            while (right[i] +1 < n && height[right[i] +1] >= height[i])
                right[i] = right[right[i] +1];
        }
        
        for (int i = 0; i < n; i++) {
            res = max(res, height[i] * (right[i] - left[i] +1));
        }
        
        return res;
    }
};
