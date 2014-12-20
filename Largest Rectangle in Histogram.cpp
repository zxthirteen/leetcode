/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
[pic]

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
[pic]

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
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
