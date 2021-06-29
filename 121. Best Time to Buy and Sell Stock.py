from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        min_price = prices[0]
        for price in prices:
            ##min_price : find out the min price in prices
            min_price = min(min_price, price)
            profit = price - min_price
            max_profit = max(max_profit, profit)
        return max_profit

    ####native method ,but TLE:
    def maxProfit_TLE(self, prices: List[int]) -> int:
        maxprofit = 0
        for buy_day in range(len(prices)):
            for sell_day in range(buy_day + 1, len(prices)):
                profit = prices[sell_day] - prices[buy_day]
                maxprofit = max(maxprofit, profit)
        return maxprofit
