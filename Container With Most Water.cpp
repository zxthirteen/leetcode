/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

/*
这个题看似和一堆矩阵里最大的面积类似，但其实用那个的O(n)方法是不行的，下面是一个试图模仿的算法：
这样在10, 14, 2, 12这个例子中过不了，因为求12的左边界时会去找2的左边界也就是位置0，但是发现[0]处的最大值是10，比12小，所有就不找了
这样的话12的左边界就没有找到（应该是[1]），这就是出错的地方
正确的方法见后面的代码，也是O(n)
*/
class Solution { // 这是错误方法！！！
public:
    int maxArea(vector<int> &height) {
        if (height.size() <= 1) return 0;
        
        int res = 0;
        int n = height.size();
        
        int maxsofar = 0;
        vector<int> left(n, 0), right(n, 0);
        vector<int> maxleft(n, 0), maxright(n, 0);
        
        for (int i = 0; i < n; i++) {
            maxsofar = max(maxsofar, height[i]);
            maxleft[i] = maxsofar;
            left[i] = i;
            
            while (left[i] -1 >= 0 && maxleft[left[i] -1] >= height[i])
                left[i] = left[left[i] -1];
        }
        
        maxsofar = 0;
        for (int i = n-1; i >= 0; i--) {
            maxsofar = max(maxsofar, height[i]);
            maxright[i] = maxsofar;
            right[i] = i;
            while (right[i] +1 < n && maxright[right[i] +1] >= height[i])
                right[i] = right[right[i] +1];
        }
        
        for (int i = 0; i < n; i++) {
            res = max(res, min(height[left[i]], height[right[i]]) * (right[i] - left[i]));
        }
        
        return res;
    }
};

/*
这里用到一个事实，如果在i 和 j的里面的更大的面积的话（x, y)，那么h[x] > h[i]，h[y] > h[j]
另外，对于x-1, 和 y+1两个位置，一定有x比x-1高，y比y+1高，所以在移i和j的时候，先移小的，就能保证找到x和y
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() <= 1) return 0;
        
        int res = 0;
        int n = height.size();
        
        int i = 0, j = n-1;

        while (i < j) {
            res = max(res, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]){
                i++;   
            } else {
                j--;
            }
        }
        
        return res;
    }
};