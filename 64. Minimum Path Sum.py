from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        for r in range(1, row):
            print(r)
            ###equal to the top of itself.
            grid[r][0] += grid[r - 1][0]
        for c in range(1, col):
            ###equal to the down of itself.
            grid[0][c] += grid[0][c - 1]
        for i in range(1, row):
            for j in range(1, col):
                # The best solution of this position is the minimal of the top or left to plus itself.
                m = min(grid[i - 1][j], grid[i][j - 1])
                grid[i][j] += m
        print(grid)
        return grid[-1][-1]

#         m, n = len(grid), len(grid[0])
#         ####裝飾器：目的是在不增加原本程式碼的情況下給予其功能，在此新增一個不會一直做重複運算的功能。
#         @functools.lru_cache(None)
#         def recurse(i, j):
#             if i == m-1 and j == n-1: return grid[-1][-1]
#             try:
#                 return grid[i][j] + min(recurse(i+1, j), recurse(i, j+1))
#             except:
#                 #當try發生問題後，回傳正的浮點數無限大
#                 return float('inf')

#         return recurse(0, 0)




