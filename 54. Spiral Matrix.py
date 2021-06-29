from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        return self._spiralOrder(matrix, 0, len(matrix[0]) - 1, len(matrix) - 1, ans)

    def _spiralOrder(self, matrix: List[List[int]], Top: int, R: int, B: int, ans: List[int]) -> List[int]:
        L = T = Top
        ###########Top-left to Top-right
        while R >= 0 and L <= R:
            # we will always do this parts.
            ans.append(matrix[T][L])
            L += 1
        L -= 1  # L is out of boundary,so let it back.
        ###########Top-right to Bottom-right
        while T < B and Top < B and R >= Top:
            T += 1
            ans.append(matrix[T][R])
        ###########Bottom-right to Bottom-left
        while R > 0 and L > Top and Top < B:
            # R>0:So we know we have over two line in this run.
            # L>Top:L is going to be stay in the boundary.
            L -= 1
            ans.append(matrix[B][L])
        ###########Bottom-left to Top-left minus 1
        while R > Top and T - 1 > Top:
            T -= 1
            ans.append(matrix[T][L])
        if Top + 1 < B and R > Top:
            # Recursivly call the innor circule.
            self._spiralOrder(matrix, Top + 1, R - 1, B - 1, ans)
        return ans










