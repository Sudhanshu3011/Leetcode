
// You are given an array prices where prices[i] represents the price of a given stock on the i-th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Constraints:
// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// You can only complete one transaction (buy one and sell one share of the stock).
// Example:
// Input: prices = [7, 1, 5, 3, 6, 4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 3 is not allowed because you must sell before you can buy again.

class Solution {
    public int maxProfit(int[] prices) {
        
        int minimum=prices[0];
        int cost, profit=0;

        for(int i=0;i<prices.length;i++)
        {
            cost= prices[i]- minimum;
            profit=Math.max(profit,cost);

            minimum=Math.min(minimum,prices[i]);

        }

        return profit;
    }
}