/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (43.86%)
 * Total Accepted:    88.5K
 * Total Submissions: 201.8K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */
/*
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (41.66%)
 * Total Accepted:    54.2K
 * Total Submissions: 130K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like
 * (ie, buy one and sell one share of the stock multiple times) with the
 * following restrictions:
 *
 *
 * ⁠   You may not engage in multiple transactions at the same time (ie, you
 * must sell the stock before you buy again).
 * ⁠   After you sell your stock, you cannot buy stock on next day. (ie,
 * cooldown 1 day)
 *
 *
 * Example:
 *
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
 *
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
/*
 * thinking:
 * must sell / cooldown last day
 * maxProfit = maxProfit at last sell day
 * maxProfitSellAtDay(n): max profit at day n if sell at day n
 * maxProfitSellAtDay(1) = prices[1] - prices[0]
 * maxProfitSellAtDay(n) = max( // n: sell
 *   // n-1: sell -> cool down
 *   prices[n] - prices[n-1] + maxProfitSellAtDay(n-1),
 *   // n-1: cooldown -> buy if n-2 cooldown
 *   prices[n] - prices[n-1] + maxProfitSellAtDay(0 ~ n-3),
 * )
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int maxProfit = INT_MIN;
    if (prices.size() <= 1) {
      return 0;
    }
    for (int i = prices.size() - 1; i > 0; i--) {
      prices[i] = prices[i] - prices[i - 1];
    }
    prices[0] = INT_MIN;
    // cout << prices << endl;
    for (int i = 2; i < prices.size(); i++) {
      if (i >= 4 && prices[i - 3] > maxProfit) {
        maxProfit = prices[i - 3];
      }
      if (i >= 2) {
        prices[i] += max(0, max(maxProfit, prices[i - 1]));
      }
    }
    // cout << prices << endl;
    for (int i = prices.size() > 3 ? prices.size() - 3 : 0; i < prices.size();
         i++) {
      if (prices[i] > maxProfit) {
        maxProfit = prices[i];
      }
    }
    return maxProfit > 0 ? maxProfit : 0;
  }
};

