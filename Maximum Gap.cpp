/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

/* 用桶排序, 一个优化是每个桶里可以只保留最大值和最小值 */

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = num.size();
        if (n < 2) return 0;
        
        int max = num[0], min = num[0];
        for (int i = 1; i < n; i++) {
            if (num[i] > max) {
                max = num[i];
            }
            if (num[i] < min) {
                min = num[i];
            }
        }
        
        vector<vector<int> > buckets (n+1, vector<int>());
        int unit = (max - min)/n+1;
        for (int i = 0; i < n; i++) {
            int index = (num[i] - min)/unit;
            if (buckets[index].size() == 0) {
                buckets[index].push_back(num[i]);
            } else if (buckets[index].size() == 1) {
                if (num[i] > buckets[index][0]) {
                    buckets[index].push_back(num[i]);
                } else {
                    buckets[index].insert(buckets[index].begin(), num[i]);
                }
            } else {
                if (num[i] > buckets[index].back()) {
                    buckets[index].back() = num[i];
                } else if (num[i] < buckets[index].front()) {
                    buckets[index].front() = num[i];
                }
            }
        }
        
        int res = INT_MIN;
        int last = INT_MIN;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                res = std::max(res, buckets[i][j] - last);
                last = buckets[i][j];
            }
        }
        return res;
    }
};