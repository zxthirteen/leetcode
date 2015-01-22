/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int minsofar = prices[0];
        int profit = 0;
        
        for (int i = 0; i < n; i++) {
            minsofar = min(minsofar, prices[i]);
            if (i == n-1 || prices[i] > prices[i+1]) {
                // 这时不可能有交易在i左边开始并且在i+1右边结束，
                // 因为如果这样做，不如在i点卖再在i+1买
                profit += prices[i] - minsofar;
                minsofar = INT_MAX;
            }
        }
        return profit;
    }
};