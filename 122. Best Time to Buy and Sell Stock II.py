from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        for i in range(len(prices) - 1):
            ##because the max profit can be separate to the addition from the several small profits.
            ##so we only need to get the profit if the day is worth to sell.
            if prices[i + 1] > prices[i]:
                maxprofit += prices[i + 1] - prices[i]
        return maxprofit

        ### notice : you must sell the stock before you buy again
        ### so the ans of this case "[1,1,5,1,1,6,1,1,7]"  is 4+5+6=15

