/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int minsofar = prices[0];
        int profit = 0;
        for (int i = 0; i < n; i++) {
            minsofar = min(minsofar, prices[i]);
            profit = max(profit, prices[i] - minsofar);
        }
        return profit;
    }
};