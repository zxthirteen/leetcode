/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/* 向后做一次最大profit，再向前做一次，计录结果，再枚举中间分界点，时间O(n) */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        
        vector<int> frontprofit(n, 0);
        vector<int> backprofit(n, 0);
        
        int profit = 0;
        int minsofar = prices[0];
        for (int i = 0; i < n; i++) {
            minsofar = min(minsofar, prices[i]);
            profit = max(profit, prices[i] - minsofar);
            frontprofit[i] = profit;
        }
        
        profit = 0;
        int maxsofar = prices[n-1];
        for (int i = n-1; i >= 0; i--) {
            maxsofar = max(maxsofar, prices[i]);
            profit = max(profit, maxsofar - prices[i]);
            backprofit[i] = profit;
        }
        
        int res = max(frontprofit[n-1], backprofit[0]);
        // i is the sell time of first transection
        for (int i = 1; i < n-2; i++) {
            res = max(res, frontprofit[i] + backprofit[i+1]);
        }
        return res;
    }
};